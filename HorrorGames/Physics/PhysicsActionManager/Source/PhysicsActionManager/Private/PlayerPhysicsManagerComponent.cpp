// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPhysicsManagerComponent.h"
#include "Camera/CameraComponent.h"
#include "InteractInterface.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"


// Sets default values for this component's properties
UPlayerPhysicsManagerComponent::UPlayerPhysicsManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	// You can turn these features off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("Physics handle"));
}


// Called when the game starts
void UPlayerPhysicsManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	// Check if the physics handle is initiated
	if (!PhysicsHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("UPhysicsHandle is missing"));
	}
    
	CurrentState = EInteractionAction::None;
	PreviousState = CurrentState;
}


// Called every frame
void UPlayerPhysicsManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	switch (CurrentState)
	{
	case EInteractionAction::None:
		break;
	case EInteractionAction::Interact:
		//UE_LOG(LogTemp, Error, TEXT("interact"));
		InteractObject->Interact();
		break;
	case EInteractionAction::Grab:
		//UE_LOG(LogTemp, Error, TEXT("Grab"));
		UpdatePhysicsHandleWithCameraAlignment();
		break;
	case EInteractionAction::Rotate:
		//UE_LOG(LogTemp, Error, TEXT("Rotate"));
		PerformRotation();
		break;
	case EInteractionAction::ModifyDistance:
		//UE_LOG(LogTemp, Error, TEXT("ModDist"));
		break;
	case EInteractionAction::Throw:
		//UE_LOG(LogTemp, Error, TEXT("throw"));
		PerformThrowAction();
		break;
	}
}

// ==============================================
// Public functions called from first person view
// ==============================================

void UPlayerPhysicsManagerComponent::Grab()
{
    // Only allow grabbing when in the None state
    if (IsInteracting()){return;}


    // Check if both PhysicsHandle and PlayerCamera are available
    if(!PhysicsHandle || !PlayerCamera){return;}

    // Perform a line trace to determine what was hit, and assign the result to LastHitResult
    if (!(LastHitResult = PerformLineTrace(PlayerCamera->GetComponentLocation(), GetLineTraceEnd())).GetActor())
    {
        return;
    }
    
    // Check if the hit object implements the interact interface
    if (IInteractInterface* InteractableObject = Cast<IInteractInterface>(LastHitResult.GetActor()))
    {
        // Set up interaction with the object
        bIsCameraRotationLocked = true;
        SetInteractInterface(InteractableObject);
        TransitionState(EInteractionAction::Interact);
    }
    else
    {
        // If not an interactable object, attempt to grab it
        GrabWithPhysicsHandle(LastHitResult);
        TransitionState(EInteractionAction::Grab);
    }
}

void UPlayerPhysicsManagerComponent::Release()
{
    if (PhysicsHandle)
    {
        PhysicsHandle->ReleaseComponent();
    }

    TransitionState(EInteractionAction::None);
    LastHitResult = FHitResult(); // Reset the interaction flag
    RotationDifference = FRotator::ZeroRotator;
    AdjustedReach = 0.f;
    bIsCameraRotationLocked = false;
    OriginalRotationBeforeLock = FRotator::ZeroRotator;
}

void UPlayerPhysicsManagerComponent::Throw()
{
    if(IsPhysicsInteractionState(CurrentState))
    {
        OriginalRotationBeforeLock = FRotator::ZeroRotator;
        TransitionState(EInteractionAction::Throw);
    }
}

void UPlayerPhysicsManagerComponent::ModifyDistance(const float InputDelta)
{
    TransitionState(EInteractionAction::ModifyDistance);
    if(IsPhysicsInteractionState(CurrentState))
    {
        AdjustReachWithInput(InputDelta);
        TransitionState(PreviousState);
    }
}

void UPlayerPhysicsManagerComponent::Rotate()
{
    if(IsPhysicsInteractionState(CurrentState) && PhysicsHandle->GetGrabbedComponent())
    {
        TransitionState(EInteractionAction::Rotate);
        UE_LOG(LogTemp, Error, TEXT("rotating"));
    }
}

void UPlayerPhysicsManagerComponent::StopRotate()
{
    if(!IsPhysicsInteractionState(CurrentState)) return;
    bIsCameraRotationLocked = false;
    OriginalRotationBeforeLock = FRotator::ZeroRotator;
    RotationDifference = FRotator::ZeroRotator;
    GoToPreviousState();
    UE_LOG(LogTemp, Error, TEXT("not rotating"));
}

// ==============================================
// Object manipulation functions
// ==============================================

void UPlayerPhysicsManagerComponent::GrabWithPhysicsHandle(const FHitResult& HitResult)
{
    bIsCameraRotationLocked = false;
    if (!PhysicsHandle || !HitResult.GetActor()) {return;}

    if (UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent())
    {
        // Grab the component using PhysicsHandle
        PhysicsHandle->GrabComponentAtLocationWithRotation(
            ComponentToGrab,
            NAME_None,
            ComponentToGrab->GetCenterOfMass(),
            ComponentToGrab->GetComponentRotation()
        );
    }    
}

void UPlayerPhysicsManagerComponent::PerformThrowAction()
{
    bIsCameraRotationLocked = false;
    if (!PhysicsHandle){return;}
    
    if(UPrimitiveComponent* ComponentGrabbed = PhysicsHandle->GetGrabbedComponent())
    {
        PhysicsHandle->ReleaseComponent();
        
        /// (Using player's forward vector to determine direction of throw).
        ComponentGrabbed->AddImpulse(
            PlayerCamera->GetForwardVector() * ThrowStrength,
            NAME_None, /// No bone names for specific  objects.
            true /// Makes sure that mass is immaterial to the force.
        );
    }
    Release();
}

void UPlayerPhysicsManagerComponent::UpdatePhysicsHandleWithCameraAlignment()
{
    bIsCameraRotationLocked = false;
    if (!PhysicsHandle || !PlayerCamera){return;}
    
    CalculateRotationDifference();
    if (PhysicsHandle && PlayerCamera)
    {
        PhysicsHandle->SetTargetLocation(GetLineTraceEnd());
        PhysicsHandle->SetTargetRotation(PlayerCamera->GetComponentRotation() + RotationDifference);
    }
}

void UPlayerPhysicsManagerComponent::PerformRotation()
{
    if(!PhysicsHandle->GetGrabbedComponent()) // Goes back to none interaction if object is not grabbed else lock camera rotation
    {
       TransitionState(EInteractionAction::None);
    }
    else
    {
        bIsCameraRotationLocked = true;
    }

    if (OriginalRotationBeforeLock.IsZero() && PlayerCamera) // Goes back to none interaction if object is not grabbed
    {
        OriginalRotationBeforeLock = PhysicsHandle->GetGrabbedComponent()->GetComponentRotation();
    }
    
   if(PhysicsHandle && PhysicsHandle->GetGrabbedComponent())
   {
       OriginalRotationBeforeLock.Yaw -= DeltaRotationInput.X;
       OriginalRotationBeforeLock.Pitch -= DeltaRotationInput.Y;
       PhysicsHandle->SetTargetLocation(GetLineTraceEnd());
       PhysicsHandle->SetTargetRotation(OriginalRotationBeforeLock);
   }
   else
   {
       StopRotate();
   }
}


// ==============================================
// State management functions
// ==============================================

bool UPlayerPhysicsManagerComponent::IsPhysicsInteractionState(const EInteractionAction StateToCheck) const
{
    return (StateToCheck == EInteractionAction::None || StateToCheck == EInteractionAction::Interact) ? false : true;
}

void UPlayerPhysicsManagerComponent::TransitionState(const EInteractionAction NewState)
{
    if (CurrentState != NewState)
    {
        PreviousState = CurrentState;
        CurrentState = NewState;
    }
}

// ==============================================
// Calculation functions
// ==============================================

void UPlayerPhysicsManagerComponent::CalculateRotationDifference()
{
    if (PhysicsHandle && PhysicsHandle->GrabbedComponent && PlayerCamera)
    {
        if (RotationDifference.IsZero())
        {
            RotationDifference = PhysicsHandle->GrabbedComponent->GetComponentRotation() - PlayerCamera->GetComponentRotation();
        }
    }
}

void UPlayerPhysicsManagerComponent::AdjustReachWithInput(const float& InputDelta)
{
    if (PhysicsHandle && PhysicsHandle->GrabbedComponent)
    {
        // Calculate the new adjusted reach value based on input delta and sensitivity,
        // then clamp it within the specified range limits.
        AdjustedReach = FMath::Clamp(AdjustedReach + (-InputDelta * DistanceSensitivity), 0.f, Reach);
    }
}

// ==============================================
// Functions assisting Line Tracing
// ==============================================

FVector UPlayerPhysicsManagerComponent::GetLineTraceEnd() const
{
    // Get the player's viewpoint
    const FVector PlayerViewPointLocation = PlayerCamera->GetComponentLocation();
    const FRotator PlayerViewPointRotation = PlayerCamera->GetComponentRotation();
    // Calculate and return the line trace end location
    return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * (Reach - AdjustedReach);
}

FHitResult UPlayerPhysicsManagerComponent::PerformLineTrace(const FVector& StartLocation, const FVector& EndLocation)
{
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(GetOwner());

    FHitResult HitResult;
    GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, Params);
    
    if(HitResult.GetActor())
    {
        FVector PlayerViewPointLocation = PlayerCamera->GetComponentLocation();
        FRotator PlayerViewPointRotation = PlayerCamera->GetComponentRotation();
        FVector ComponentDistance = HitResult.GetActor()->GetActorLocation();
        float DistanceToHit = FVector::Distance(ComponentDistance, (PlayerViewPointLocation + PlayerViewPointRotation.Vector()));
        // Determine the adjusted reach based on the grab distance
        AdjustedReach = FMath::Clamp(Reach - DistanceToHit, 0.f, Reach);
    }

    return HitResult;
}

