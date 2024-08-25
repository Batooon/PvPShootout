// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootoutPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "PvPShootout/PvPShootoutCharacter.h"
#include "PvPShootout/TP_WeaponComponent.h"

void AShootoutPlayerController::BeginPlay()
{
    Super::BeginPlay();

    AssignWeapon();

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(InputMappingContext, 0);
    }
}

AActor* AShootoutPlayerController::SpawnWeapon()
{
    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    AActor* Rifle = GetWorld()->SpawnActor<AActor>(RifleClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
    return Rifle;
}

void AShootoutPlayerController::AssignWeapon()
{
    if (AActor* Rifle = SpawnWeapon())
    {
        if(UTP_WeaponComponent* WeaponComponent = Rifle->FindComponentByClass<UTP_WeaponComponent>())
        {
            APvPShootoutCharacter* shootoutCharacter = Cast<APvPShootoutCharacter>(GetCharacter());
            WeaponComponent->AttachWeapon(shootoutCharacter);
        }
    }
}
