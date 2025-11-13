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
    UMaterialInterface* WallMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/SM_Roads_05/Materials/Roads_05/MT00051-Pavement/MI_MT00051_Pavement.MI_MT00051_Pavement"));

    UStaticMesh* FloorMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane.Plane"));
    UMaterialInterface* FloorMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/SM_Roads_05/Materials/Roads_05/MT00051-Pavement/MI_MT00051_Pavement.MI_MT00051_Pavement"));

    UStaticMesh* CeilingMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane.Plane"));
    UMaterialInterface* CeilingMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/SM_Roads_05/Materials/Roads_05/MT00051-Pavement/MI_MT00051_Pavement.MI_MT00051_Pavement"));


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
    //registering light component
    const auto& Rooms = MyDungeon.getRooms();
    for (const auto& Room : Rooms)
    {
        TArray<FIntPoint> WallPos_ = MyDungeon.Wall_Torch_Positions(Room);
        if (WallPos_.IsEmpty()) {
            continue;
        }
     
        //UStaticMesh* TorchMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Dungeon_props_pack/Props/Static_Mesh/SM_torch06.SM_torch06"));
        UStaticMesh* TorchMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cone.Cone"));
        FIntPoint POI = WallPos_[FMath::RandRange(0, WallPos_.Num() - 1)];
        //*.4 guess and check like height lol
        FVector WallPosPoint(POI.X * TileSize , POI.Y * TileSize, CeilingZ * 0.4f);
        FVector WallPos((POI.X * TileSize) - 20, POI.Y * TileSize, CeilingZ * 0.4f);
        
        UStaticMeshComponent* TorchComponent = NewObject<UStaticMeshComponent>(this);
        TorchComponent->SetStaticMesh(TorchMesh);
        TorchComponent->SetWorldLocation(WallPos);
        TorchComponent->SetWorldScale3D(FVector(0.5f));
        TorchComponent->SetWorldRotation(FRotator(0.0f, 0.0f, 180.0f));
        TorchComponent->RegisterComponent();
        TorchComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
        

        UPointLightComponent* PointLight = NewObject<UPointLightComponent>(this);
        PointLight->RegisterComponent();
        PointLight->SetIntensity(1000.0f);
        PointLight->SetLightColor(FLinearColor(1.0f, 0.8f, 0.6f)); // warm torchlight
        PointLight->SetAttenuationRadius(500.0f);
        PointLight->SetCastShadows(true);
        PointLight->SetWorldLocation(WallPosPoint);
        PointLight->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
        /*
        PointLight->SetCastShadows(true);
        PointLight->AttachToComponent(TorchComponent, FAttachmentTransformRules::KeepRelativeTransform);
        PointLight->SetRelativeLocation(FVector(0.f, 0.f, 50.f)); // small offset above torch flame
        PointLight->RegisterComponent();
        */
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
    //overlap event handler 
    //registering this to be the collision 
    ExitCollide->OnComponentBeginOverlap.AddDynamic(this, &ADungeonGenerator::OverlapExit);


    ExitCollide->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
    
}

 
void ADungeonGenerator::RegenerateDungeon()
{
    //destroy all spawned static meshes- walls, floor, etc..
    TArray<UStaticMeshComponent*> StaticMeshes;
    GetComponents<UStaticMeshComponent>(StaticMeshes);
    for (UStaticMeshComponent* SM : StaticMeshes)
    {
        if (SM && SM != MeshComponent)
        {
            SM->DestroyComponent();
        }
    }
    //felt like the light points were not deleting causing excess light
    //destroy all point lights
    TArray<UPointLightComponent*> PointLights;
    GetComponents<UPointLightComponent>(PointLights);
    for (UPointLightComponent* PL : PointLights)
    {
        if (PL)
        {
            PL->DestroyComponent();
        }
    }
    
}

// Called every frame
void ADungeonGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
   // APlayerController* PC = GetWorld()->GetFirstPlayerController();
    //if (PC && PC->WasInputKeyJustPressed(EKeys::R))
    //{
       //TO DO FIX REGEN
    //    RegenerateDungeon();
   // }
}

void ADungeonGenerator::OverlapExit(UPrimitiveComponent* obj, AActor* actor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
    // if the player is the same as the actor pointer
    //doing this if i ever wanted to add enemies
    if (ACharacter* player = Cast<ACharacter>(actor))
    {
        RegenerateDungeon();
        BeginPlay(); 
    }
}