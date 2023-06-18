// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

UCLASS()
class ARENABATTLE_API AFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Body;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Water;

	UPROPERTY(VisibleAnywhere)
	UPointLightComponent *Light;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent *Splash;

	UPROPERTY(EditAnywhere, Category=ID)
	int32 ID;

	//ȸ�� ������Ʈ ����
	UPROPERTY(ViSibleAnywhere)
	URotatingMovementComponent* Movement;

	/* �츮�� ȸ����Ű���� �� ���ӵ��� ���� ������ ����, �̸� ����� �м��븦 Z���� �������� ȸ����Ų��. �� �ӵ� ������ �� �����̹Ƿ� �����Ϳ��� ������ �� �ְ�
	UPROPERY ��ũ�ο� EditAnywhere Ű���带 �ִ´�. UPROPERTY ��ũ�ο� AllowPrivateAccess ��� META Ű���带 �߰��ϸ� �����Ϳ����� �̸� �����԰� ���ÿ� ���� �����͸�
	������ �� �ְ� �� ���α׷��� �������� ĸ��ȭ�� ����������. */
private:
	UPROPERTY(EditAnywhere, Category=Stat, Meta = (AllowPrivateAcces = ture))
	float RotateSpeed;

};
