// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonGenerator.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"


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
    //TODO 
    //randomize
    Dungeon MyDungeon(50, 40, 12, 5, 10);
    MyDungeon.generateDungeon();


    const auto& Grid = MyDungeon.getGrid();

 
    UStaticMesh* WallMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    const float TileSize = 100.0f;
    for (int y = 0; y < Grid.size(); ++y)
    {
        for (int x = 0; x < Grid[y].size(); ++x)
        {
            int tile = Grid[y][x];
            if (tile != WALL_TILE || !MyDungeon.edgeWall(x,y))
            {
                continue; // Skip non-wall tiles
            }

          
            FVector Position = FVector(x * TileSize, y * TileSize, 50.0f); // Z = 50

           
            UStaticMeshComponent* WallComponent = NewObject<UStaticMeshComponent>(this);
            WallComponent->RegisterComponent();
            WallComponent->SetStaticMesh(WallMesh);

            
          
            WallComponent->SetWorldLocation(Position);
            WallComponent->SetWorldScale3D(FVector(1.0f, 1.0f, 10.0f));  
            WallComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
        }
    }

    auto start = MyDungeon.getstart();
    auto exit = MyDungeon.getexit();

    FVector PlayerSpawn(start.first * TileSize, start.second * TileSize, 120.f);
    ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (Player)
    {
        Player->SetActorLocation(PlayerSpawn);
    }

    FVector ExitPos(exit.first * TileSize, exit.second * TileSize, 100.0f);
   /*StaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    UStaticMeshComponent* ExitMarker = NewObject<UStaticMeshComponent>(this);
    ExitMarker->RegisterComponent();
    ExitMarker->SetStaticMesh(CubeMesh);
    ExitMarker->SetWorldLocation(ExitPos);
    ExitMarker->SetWorldScale3D(FVector(1.0f, 1.0f, 0.2f));

    ExitMarker->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
    */
}

 
void ADungeonGenerator::RegenerateDungeon()
{
    TArray<UActorComponent*> Components;
    GetComponents(UStaticMeshComponent::StaticClass(), Components);
    for (UActorComponent* Comp : Components)
    {
        if (Comp != MeshComponent)
        {
            Comp->DestroyComponent();
        }
    }

}


// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC && PC->WasInputKeyJustPressed(EKeys::R))
    {
    //TO DO FIX REGEN
        RegenerateDungeon();
    }

}


