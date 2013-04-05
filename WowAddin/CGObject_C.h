#pragma once

enum TypeID
{
    TYPEID_OBJECT           = 0,
    TYPEID_ITEM             = 1,
    TYPEID_CONTAINER        = 2,
    TYPEID_UNIT             = 3,
    TYPEID_PLAYER           = 4,
    TYPEID_GAMEOBJECT       = 5,
    TYPEID_DYNAMICOBJECT    = 6,
    TYPEID_CORPSE           = 7,
    NUM_TYPEIDS             = 8
};

struct C3Vector
{
    float X, Y, Z;
};

class CGObject_C // sizeof(CGObject_C) == 0xD0
{
public:
    template <typename T> T& GetValue(uint32 index) const { return *((T*)&m_data[index]); }

    virtual ~CGObject_C(); // 0
    virtual void Disable(); // 1
    virtual void Reenable(); // 2 Reenable(CClientObjCreate  const&)
    virtual void PostReenable(); // 3 PostReenable(CClientObjCreate  const&)
    virtual void HandleOutOfRange(); // 4 HandleOutOfRange(OUT_OF_RANGE_TYPE)
    virtual void UpdateWorldObject(); // 5 UpdateWorldObject(int)
    virtual void ShouldFadeout(); // 6
    virtual void UpdateDisplayInfo(); // 7 UpdateDisplayInfo(int)
    virtual void GetNamePosition(); // 8
    virtual void GetBag(); // 9
    virtual void GetBag2(); // 10
    virtual C3Vector& GetPosition(C3Vector &pos); // 11 GetPosition(C3Vector &)
    virtual C3Vector& GetRawPosition(C3Vector &pos); // 12 GetRawPosition(C3Vector &)
    virtual float GetFacing(); // 13
    virtual float GetRawFacing(); // 14
    virtual float GetScale(); // 15
    virtual uint64 GetTransportGUID(); // 16
    virtual void GetRotation(); // 17 returns C4Quaternion
    virtual void SetFrameOfReference(); // 18 SetFrameOfReference(C44Matrix  const*)
    virtual BOOL IsQuestGiver(); // 19
    virtual void RefreshInteractIcon(); // 20
    virtual void UpdateInteractIcon(); // 21
    virtual void UpdateInteractIconAttach(); // 22
    virtual void UpdateInteractIconScale(); // 23
    virtual BOOL GetModelFileName(char const** modelFileName); // 24 GetModelFileName(char  const**)
    virtual void ScaleChangeUpdate(); // 25
    virtual void ScaleChangeFinished(); // 26
    virtual void RenderTargetSelection(); // 27
    virtual void RenderPetTargetSelection(); // 28
    virtual void Render(); // 29
    virtual void GetSelectionHighlightColor(); // 30 GetSelectionHighlightColor(CImVector *)
    virtual float GetTrueScale(); // 31
    virtual void ModelLoaded(); // 32 ModelLoaded(CM2Model *)
    virtual void ApplyAlpha(); // 33 ApplyAlpha(uint)
    virtual void PreAnimate(); // 34 PreAnimate(CGWorldFrame *)
    virtual void Animate(); // 35 Animate(float)
    virtual void ShouldRender(); // 36 ShouldRender(uint,int &,int &)
    virtual float GetRenderFacing(); // 37
    virtual void OnSpecialMountAnim(); // 38
    virtual BOOL IsSolidSelectable(); // 39
    virtual void Dummy40(); // 40
    virtual BOOL CanHighlight(); // 41
    virtual BOOL CanBeTargetted(); // 42
    virtual void FloatingTooltip(); // 43
    virtual void OnRightClick(); // 44
    virtual BOOL IsHighlightSuppressed(); // 45
    virtual void OnSpellEffectClear(); // 46 OnSpellEffectClear(CEffect *)
    virtual void GetAppropriateSpellVisual(); // 47 GetAppropriateSpellVisual(SpellRec  const*,SpellVisualRec &,int,int)
    virtual void ConnectToLightningThisFrame(); // 48 ConnectToLightningThisFrame(uint,int)
    virtual void GetMatrix(); // 49
    virtual void ObjectNameVisibilityChanged(); // 50 
    virtual void UpdateObjectNameString(); // 51 UpdateObjectNameString(int,char *,uint)
    virtual void ShouldRenderObjectName(); // 52 ShouldRenderObjectName(int)
    virtual void GetObjectModel(); // 53
    virtual const char* GetObjectName(); // 54
    virtual void GetPageTextID(); // 55 GetPageTextID(void (*)(int,ulong long  const&,void *,bool))
    virtual void CleanUpVehicleBoneAnimsBeforeObjectModelChange(); // 56
    virtual void ShouldFadeIn(); // 57
    virtual float GetBaseAlpha(); // 58
    virtual BOOL IsTransport(); // 59
    virtual BOOL IsPointInside(); // 60 IsPointInside(C3Vector  const&)
    virtual void AddPassenger(); // 61 AddPassenger(CPassenger *,int)
    virtual float GetSpeed(); // 62
    virtual void PlaySpellVisualKit_PlayAnims(); // 63 PlaySpellVisualKit_PlayAnims(SpellRec  const*,SpellVisualKitRec  const*,SPELL_VISUAL_KIT_TYPE,C3Vector  const*,int,int,ulong long,ulong,SpellVisualRec  const*,uint,int)
    virtual void PlaySpellVisualKit_HandleWeapons(); // 64 PlaySpellVisualKit_HandleWeapons(SpellRec  const*,SpellVisualKitRec  const*,C3Vector  const*,ulong long,ulong,uint,void (*)(CM2Model *,uint,uint,int,uint,ulong long,int),int *,uint,int)
    virtual void PlaySpellVisualKit_DelayLightningEffects(); // 65 PlaySpellVisualKit_DelayLightningEffects(SpellRec  const*,SpellVisualKitRec  const*,SPELL_VISUAL_KIT_TYPE,C3Vector  const*,ulong long,int,int,int,int,uint,SpellVisualRec  const*,uint,int)

    TypeID GetTypeID() const { return m_typeID; }
private:
    // void* vtable;        // 0x0
    uint32 m_field4;        // 0x4
    uint32 *m_data;         // 0x8
    uint32 m_fieldC;        // 0xC
    uint32 m_field10;       // 0x10
    TypeID m_typeID;        // 0x14
    uint32 m_field18[46];   // 0x18
};
