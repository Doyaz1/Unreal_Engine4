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

	//회전 컴포넌트 선언
	UPROPERTY(ViSibleAnywhere)
	URotatingMovementComponent* Movement;

	/* 우리가 회전시키고자 할 각속도의 값을 변수로 지정, 이를 사용해 분수대를 Z축을 기준으로 회전시킨다. 이 속도 정보는 값 유형이므로 에디터에서 편집할 수 있게
	UPROPERY 매크로에 EditAnywhere 키워드를 넣는다. UPROPERTY 매크로에 AllowPrivateAccess 라는 META 키워드를 추가하면 에디터에서는 이를 편집함과 동시에 변수 데이터를
	은닉할 수 있게 돼 프로그래밍 영역에서 캡슐화가 가능해진다. */
private:
	UPROPERTY(EditAnywhere, Category=Stat, Meta = (AllowPrivateAcces = ture))
	float RotateSpeed;

};
