// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

// #include "PlayerHUD.h"
#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "PvPShootoutPlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class PVPSHOOTOUT_API APvPShootoutPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
    UInputAction* Interact;

    void PointerPressed();
    void TryCreateAndJoinNewSession();
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;


	virtual void BeginPlay() override;
    void PointerRelease();
    UFUNCTION()
    void JoinSessionIfSucceeded(bool success);
    void JoinSession();
    virtual void SetupInputComponent() override;
};
