// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::Tick(float DeltaTime) {

	Super::Tick( DeltaTime );

	if (GetPlayerTank()) 
	{
		//Move towards the player

		//Aim to the player

		//Fire when it's ready
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	}

}

void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find a player Tank"))
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *PlayerTank->GetName())
	}
}


ATank* ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}


ATank * ATankAIController::GetPlayerTank() const {

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn){return nullptr;}
	return Cast<ATank>(PlayerPawn);



}
