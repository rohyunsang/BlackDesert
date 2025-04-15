// Fill out your copyright notice in the Description page of Project Settings.


#include "GA/BDGA_ArcherAttack.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Animation/AnimInstance.h"

UBDGA_ArcherAttack::UBDGA_ArcherAttack()
{
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UBDGA_ArcherAttack::ActivateAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const FGameplayEventData* TriggerEventData
)
{
    UE_LOG(LogTemp, Warning, TEXT("BD_LOG GA_ArcherAttack::ActivateAbility called!"));

    if (!CommitAbility(Handle, ActorInfo, ActivationInfo)) return;

    ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
    if (Character && AttackMontage)
    {
        if (UAnimInstance* AnimInstance = Character->GetMesh()->GetAnimInstance())
        {
            AnimInstance->Montage_Play(AttackMontage);
            UE_LOG(LogTemp, Log, TEXT(" Archer Attack Montage Played: %s"), *AttackMontage->GetName());
        }
    }

    EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
