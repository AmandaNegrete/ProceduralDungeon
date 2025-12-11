// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonGenerator.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Components/PointLightComponent.h"
#include <ctime>


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
    Generate();
}

void ADungeonGenerator::Generate() {
    // Create 
   //TODO: RANDDOM STREAM 
   //see blue noise proj4 
    srand(time(nullptr));

    int width = 40 + rand() % 20;
    int height = 30 + rand() % 20;
    int maxRooms = 20 + rand() % 10;
    int minSize = 5;
    int maxSize = minSize + rand() % 10;
    int thickness = 2;

    Dungeon MyDungeon(width, height, maxRooms, minSize, maxSize, thickness);
    MyDungeon.generateDungeon();

    const auto& Grid = MyDungeon.getGrid();


    UStaticMesh* WallMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    UMaterialInterface* WallMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/OldWall/Material/M_OldWall.M_OldWall"));

    UStaticMesh* FloorMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane.Plane"));
    UMaterialInterface* FloorMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/OldWall/Material/M_OldWall.M_OldWall"));

    UStaticMesh* CeilingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane.Plane"));
    UMaterialInterface* CeilingMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/OldWall/Material/M_OldWall.M_OldWall"));


    const float TileSize = 100.0f;
    const float FloorZ = 1.0f;
    const float CeilingZ = 550.0f;
    for (int y = 0; y < Grid.size(); ++y)
    {
        for (int x = 0; x < Grid[y].size(); ++x)
        {
            int tile = Grid[y][x];

            //if (tile == FLOOR_TILE) {
            //
            //}
            if (tile == WALL_TILE && MyDungeon.edgeWall(x, y))
            {
                FVector Position = FVector(x * TileSize, y * TileSize, 50.0f); // Z = 50


                UStaticMeshComponent* WallComponent = NewObject<UStaticMeshComponent>(this);
                WallComponent->RegisterComponent();
                WallComponent->SetStaticMesh(WallMesh);
                if (WallMaterial)
                {
                    WallComponent->SetMaterial(0, WallMaterial);
                }

                WallComponent->SetWorldLocation(Position);
                WallComponent->SetWorldScale3D(FVector(1.0f, 1.0f, 10.0f));
                WallComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
            }

            if (tile == FLOOR_TILE) {
                FVector FloorPosition = FVector(x * TileSize, y * TileSize, FloorZ + 1); // Z = 50


                UStaticMeshComponent* FloorComponent = NewObject<UStaticMeshComponent>(this);
                FloorComponent->RegisterComponent();
                FloorComponent->SetStaticMesh(FloorMesh);
                if (FloorMaterial)
                {
                    FloorComponent->SetMaterial(0, FloorMaterial);
                }

                FloorComponent->SetWorldLocation(FloorPosition);
                FloorComponent->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));
                FloorComponent->SetWorldScale3D(FVector(TileSize / 100.0f, TileSize / 100.0f, 1.0f));
                FloorComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
            }

            if (tile == FLOOR_TILE) {
                FVector CeilingPosition = FVector(x * TileSize, y * TileSize, CeilingZ - 2); // Z = 50


                UStaticMeshComponent* CeilingComponent = NewObject<UStaticMeshComponent>(this);
                CeilingComponent->RegisterComponent();
                CeilingComponent->SetStaticMesh(CeilingMesh);
                if (CeilingMaterial)
                {
                    CeilingComponent->SetMaterial(0, CeilingMaterial);
                }

                CeilingComponent->SetWorldLocation(CeilingPosition);
                CeilingComponent->SetWorldRotation(FRotator(180.0f, 0.0f, 0.0f));
                CeilingComponent->SetWorldScale3D(FVector(TileSize / 100.0f, TileSize / 100.0f, 1.0f));
                CeilingComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
            }



        }
    }
    // UStaticMesh* TorchMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cone.Cone"));
     //registering light component
    const auto& Rooms = MyDungeon.getRooms();
    for (const auto& Room : Rooms)
        if (FMath::RandRange(0, 1) == 0) {
            {
                TArray<FIntPoint> WallPos_ = MyDungeon.Wall_Torch_Positions(Room);
                TArray<FIntPoint> LightPos_ = MyDungeon.Wall_LightPoint_Positions(Room);
                if (WallPos_.IsEmpty()) {
                    continue;
                }
                if (LightPos_.IsEmpty()) {
                    continue;
                }


                UStaticMesh* TorchMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cone.Cone"));
                FIntPoint POI = WallPos_[FMath::RandRange(0, WallPos_.Num() - 1)];
                //the direction the wall is facing given the two 
                FVector Normal = MyDungeon.WallPositionSet(POI.X, POI.Y);
                //so it ss INSIDE WALL
                float offset = -40.0f;
                //world pos calculation 
                FVector TorchPosition(
                    POI.X * TileSize + Normal.X * offset,
                    POI.Y * TileSize + Normal.Y * offset,
                    CeilingZ * 0.4f
                );

                FVector2D N2D(Normal.Y, -Normal.X);
                //using tan to generate the poinmt against the wall 
                //convverting vector to angle to make sure its against wall properly.
                float angle = FMath::RadiansToDegrees(FMath::Atan2(N2D.Y, N2D.X));
                FRotator TorchRotation(180, angle, 0);
                //TorchRotation.Pitch += 180.0f;
                FVector LightPos = TorchPosition + FVector(0, 0, 60.f);

                UStaticMeshComponent* TorchComponent = NewObject<UStaticMeshComponent>(this);
                UMaterialInterface* TorchMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/SM_Roads_05/Materials/Roads_05/MT00270-Pavement/MI_MT00268_Pavement.MI_MT00268_Pavement"));
                TorchComponent->SetStaticMesh(TorchMesh);
                if (TorchMesh)
                {
                    TorchComponent->SetMaterial(0, TorchMaterial);
                }
                TorchComponent->SetWorldLocation(TorchPosition);
                TorchComponent->SetWorldScale3D(FVector(0.5f));
                TorchComponent->SetWorldRotation(TorchRotation);
                TorchComponent->RegisterComponent();
                TorchComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);


                UPointLightComponent* PointLight = NewObject<UPointLightComponent>(this);
                PointLight->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
                PointLight->SetIntensity(1000.0f);
                PointLight->SetLightColor(FLinearColor(1.0f, 0.8f, 0.6f));
                PointLight->SetAttenuationRadius(400.0f);
                PointLight->SetCastShadows(true);
                PointLight->SetWorldLocation(LightPos);
                PointLight->RegisterComponent();
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
    UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Dungeon_props_pack/Props/Static_Mesh/SM_open_book.SM_open_book"));
    UStaticMeshComponent* ExitCollide = NewObject<UStaticMeshComponent>(this);
    ExitCollide->RegisterComponent();
    ExitCollide->SetStaticMesh(CubeMesh);
    ExitCollide->SetWorldLocation(ExitPos);
    ExitCollide->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
    ExitCollide->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    ExitCollide->SetGenerateOverlapEvents(true);

    UPointLightComponent* LightBook = NewObject<UPointLightComponent>(this);
    LightBook->RegisterComponent();
    LightBook->AttachToComponent(ExitCollide, FAttachmentTransformRules::KeepWorldTransform);
    LightBook->SetIntensity(4000.0f);
    LightBook->SetLightColor(FLinearColor(1.0f, 2.0f, 0.9f));
    LightBook->SetAttenuationRadius(400.0f);
    LightBook->SetCastShadows(false);

    //overlap event handler 
    //registering this to be the collision 
    ExitCollide->OnComponentBeginOverlap.AddDynamic(this, &ADungeonGenerator::OverlapExit);


    ExitCollide->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

}


 
void ADungeonGenerator::RegenerateDungeon()
{
    //destroy all spawned static meshes- walls, floor, etc..
    TArray<UActorComponent*> StaticMeshes = GetComponents().Array();
    for (UActorComponent* SM : StaticMeshes)
    {
        if (SM && SM != MeshComponent)
        {
            SM->DestroyComponent();
        }
    }
  
    
}

// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ADungeonGenerator::OverlapExit(UPrimitiveComponent* obj, AActor* actor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
    // if the player is the same as the actor pointer
    //doing this if i ever wanted to add enemies
    if (ACharacter* player = Cast<ACharacter>(actor))
    {
        RegenerateDungeon();
        Generate(); 
    }
}