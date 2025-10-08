// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonGenerator.h"

// Sets default values
ADungeonGenerator::ADungeonGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Plane.Plane"));
	if (CubeMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(CubeMesh.Object);
	}

}

// Called when the game starts or when spawned
void ADungeonGenerator::BeginPlay()
{
    Super::BeginPlay();

    // Create 
    Dungeon MyDungeon(50, 40, 12, 5, 10);
    MyDungeon.generateDungeon();

    const auto& Grid = MyDungeon.getGrid();

 
    UStaticMesh* WallMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane.Plane"));
    const float TileSize = 100.0f;
    for (int y = 0; y < Grid.size(); ++y)
    {
        for (int x = 0; x < Grid[y].size(); ++x)
        {
            int tile = Grid[y][x];
            if (tile != WALL_TILE)
            {
                continue; // Skip non-wall tiles
            }

          
            FVector Position = FVector(x * TileSize, y * TileSize, 50.0f); // Z = 50

           
            UStaticMeshComponent* WallComponent = NewObject<UStaticMeshComponent>(this);
            WallComponent->RegisterComponent();
            WallComponent->SetStaticMesh(WallMesh);

            
            FRotator Rotation = FRotator(90.0f, 0.0f, 0.0f); // Rotate 
            WallComponent->SetWorldRotation(Rotation);
            WallComponent->SetWorldLocation(Position);
            WallComponent->SetWorldScale3D(FVector(1.0f, 1.0f, 2.0f)); 
            WallComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
        }
    }

 

}


// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

