// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonGenerator.h"

// Sets default values
ADungeonGenerator::ADungeonGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADungeonGenerator::BeginPlay()
{
	Super::BeginPlay();
	//int width_, int height_, int maxRooms_, int minSize_, int maxSize_
	Dungeon MyDungeon(50, 40, 12, 5, 10);

	MyDungeon.generateDungeon();
	MyDungeon.printDungeon();

	
}

// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

