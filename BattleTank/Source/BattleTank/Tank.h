// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

// Forward declarations
class UTankMovementComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
    
    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;
    
    UFUNCTION(BlueprintPure, category = "Helth")
    float GetHealthPercent() const;
    
    FTankDelegate OnDeath;
    
protected:

    UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
    
    ATank();
    
    virtual void BeginPlay() override;
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    int32 StartingHealth = 100;
    
    UPROPERTY(VisibleAnywhere, Category = "Health")
    int32 CurrentHealth;
		
	};
