// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "PlayerPhysicsManagerComponent.generated.h"

// Forward declarations
class UPhysicsHandleComponent;
class IInteractInterface;
class UCameraComponent;

// Enumerates different interaction actions
enum class EInteractionAction
{
	None,
	Interact,
	Grab,
	Rotate,
	ModifyDistance,
	Throw
};

/**
 * Component that enables physics-based interactions with objects.
 */


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHYSICSACTIONMANAGER_API UPlayerPhysicsManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// ==============================================
	// Unreal default constructor
	// ==============================================
	UPlayerPhysicsManagerComponent();

	// ==============================================
	// Public functions called from first-person view
	// ==============================================
	void Grab(); // Initiate object grabbing (custom trigger)
	void Release(); // Release held object or cancel (custom trigger)
	void Throw(); // Throw held object (custom trigger)
	void ModifyDistance(const float InputDelta); // Modify object distance (custom trigger)
	// ==============================================
	// NOTE: Rotation System
	// This section of the code implements the object rotation feature.
	// It currently handles basic rotation functionality.
	// It misses rotation change based on mouse circular motion gesture(Implementation missing)
	// ==============================================
	void Rotate();
	void StopRotate();
	void SetCamera(UCameraComponent* Camera) {PlayerCamera = Camera;} // Set camera during BeginPlay() on the owning first-person character
	bool GetCameraRotationState() const {return  !bIsCameraRotationLocked;}
	void SetDeltaInput(const FVector2d& DeltaRotation) {DeltaRotationInput = DeltaRotation;}

protected:
	// ==============================================
	// Unreal default functions
	// ==============================================
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// ==============================================
	// Functions assisting LineTracing
	// ==============================================
	FVector GetLineTraceEnd() const;
	FHitResult PerformLineTrace(const FVector& StartLocation, const FVector& EndLocation);
	// ==============================================
	// Object manipulation functions
	// ==============================================
	void GrabWithPhysicsHandle(const FHitResult& HitResult);
	void PerformThrowAction();
	void UpdatePhysicsHandleWithCameraAlignment();
	void PerformRotation();

	// ==============================================
	// Calculation functions
	// ==============================================
	void CalculateRotationDifference();
	void AdjustReachWithInput(const float& InputDelta);

	// ==============================================
	// State management functions
	// ==============================================
	void TransitionState(const EInteractionAction NewState);
	void GoToPreviousState() {CurrentState = PreviousState;}
	bool IsPhysicsInteractionState(const EInteractionAction StateToCheck) const;
	bool IsInteracting() const {return CurrentState != EInteractionAction::None;};

	// ==============================================
	// Var Setup
	// ==============================================
	void SetInteractInterface(IInteractInterface* InteractableObject) {InteractObject = InteractableObject;};
	
	// ==============================================
	// Private Variables
	// ==============================================
	FHitResult LastHitResult = FHitResult(); // Stores information about the last hit during line tracing
	IInteractInterface* InteractObject; // Stores the object currently being interacted with
	EInteractionAction CurrentState; // Represents the current interaction state, influenced by input
	EInteractionAction PreviousState; // Keeps track of the previous state for handling complex scenarios
	FRotator RotationDifference; // Holds the difference in rotation between the player and grabbed object
	float AdjustedReach = 0.f; // Modifies the distance of object manipulation based on player input, e.g., scroll wheel
	bool bIsCameraRotationLocked = false; // A boolean indicating whether camera rotation is locked or unlocked.
	FVector2d DeltaRotationInput; // Delta input for controlling rotation along the X and Y axes
	FRotator OriginalRotationBeforeLock; // Preserves the original rotation value of the grabbed object prior to locking, capturing its state before being fixed in rotation

	// ==============================================
	// Components
	// ==============================================

	UPROPERTY()
	UPhysicsHandleComponent* PhysicsHandle;

	UPROPERTY()
	UCameraComponent* PlayerCamera;

	// ==============================================
	// Parameter variables
	// ==============================================
	
	/** Max distance between player and object to be able to interact */
	UPROPERTY(EditAnywhere, Category = "Interaction Settings")
	float Reach = 200.f;

	/** Magnitude of impulse applied to the object during the throw action */
	UPROPERTY(EditAnywhere, Category = "Interaction Settings")
	float ThrowStrength = 1000.f;
	
	/** Adjusts the sensitivity for moving the object closer or further away */
	UPROPERTY(EditAnywhere, Category = "Interaction Settings")
	float DistanceSensitivity = 10.f;
	
};
