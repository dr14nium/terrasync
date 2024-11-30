#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct InterfaceFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};

// System.Func`2<TriangleNet.Geometry.ITriangle,System.Boolean>
struct Func_2_tDDCB4765EFB0E436EECCED6ABE46E3207BC68C63;
// System.Func`3<TriangleNet.Geometry.ITriangle,System.Double,System.Boolean>
struct Func_3_tE5672D52F7EAAC12E73F6D0A3AC6882EE3E6F2C3;
// System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.ISegment>
struct IEnumerable_1_t791FF7D975FE9768FF0109CF0DEBF1F3BA6AE11E;
// System.Collections.Generic.IEnumerable`1<System.Object>
struct IEnumerable_1_tF95C9E01A913DD50575531C8305932628663D9E9;
// System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Point>
struct IEnumerable_1_t5574BA1E7B453137C3580B21A7126DFCBDA331BE;
// System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Vertex>
struct IEnumerable_1_t098854E2A31D110376650D3F538CACF454C54F22;
// System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment>
struct List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431;
// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
// System.Collections.Generic.List`1<TriangleNet.Geometry.Point>
struct List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE;
// System.Collections.Generic.List`1<TriangleNet.Geometry.RegionPointer>
struct List_1_tC9803D99D64F5D893C71690F4B65415B86B42629;
// System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>
struct List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// System.Double[]
struct DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE;
// TriangleNet.Geometry.ISegment[]
struct ISegmentU5BU5D_tBE0FE4A4777ED9BC3C74FA1CBA973A2FDC34875D;
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
// System.IntPtr[]
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// TriangleNet.Geometry.Point[]
struct PointU5BU5D_t4457033206B94B24EC4BDD2BF511DC9BE9379E17;
// TriangleNet.Geometry.RegionPointer[]
struct RegionPointerU5BU5D_t1A7AF98468D2FEF4F1A3F9D12E8526B12E13B396;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// TriangleNet.Geometry.Vertex[]
struct VertexU5BU5D_t02C037B0D0EC7CCCC8569ACFA81923FC98A27A06;
// System.ArgumentOutOfRangeException
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F;
// TriangleNet.Configuration
struct Configuration_t4555CC5B976EF0C0297F35B57FCB1BB5B656283A;
// TriangleNet.Meshing.ConstraintOptions
struct ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC;
// TriangleNet.Geometry.Contour
struct Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087;
// TriangleNet.Geometry.Edge
struct Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64;
// System.Exception
struct Exception_t;
// TriangleNet.Meshing.GenericMesher
struct GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// TriangleNet.Meshing.IMesh
struct IMesh_t8F1CCF04EE326BFFB63017721BB4E29857C8C3AC;
// TriangleNet.Geometry.IPolygon
struct IPolygon_t9315A45C2138EB4A643160026A607F92B917F9FA;
// TriangleNet.Geometry.ISegment
struct ISegment_t7C45A404D940E12DAB92D9973B6FA4B09F523949;
// TriangleNet.Geometry.ITriangle
struct ITriangle_t7B68E84B00E0B87B508BA815EB6B4AE1D960CD99;
// TriangleNet.Meshing.ITriangulator
struct ITriangulator_tE8B474FCF8BC08EF1B3FF08C841A5C6B4182ECCE;
// System.IndexOutOfRangeException
struct IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82;
// System.NotImplementedException
struct NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8;
// TriangleNet.Geometry.Point
struct Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1;
// TriangleNet.Geometry.Polygon
struct Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2;
// TriangleNet.Meshing.QualityOptions
struct QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E;
// TriangleNet.Geometry.Rectangle
struct Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B;
// TriangleNet.Geometry.RegionPointer
struct RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B;
// TriangleNet.RobustPredicates
struct RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// TriangleNet.Geometry.Segment
struct Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E;
// System.String
struct String_t;
// TriangleNet.Topology.Triangle
struct Triangle_t1D943DC9E3293CDEE67259B7C9E1A2C8E09CF642;
// TriangleNet.Geometry.Vertex
struct Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerable_1_t5574BA1E7B453137C3580B21A7126DFCBDA331BE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_1_t357504A725D78F0BC68EA02C72449D4F927A758F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ISegment_t7C45A404D940E12DAB92D9973B6FA4B09F523949_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ITriangle_t7B68E84B00E0B87B508BA815EB6B4AE1D960CD99_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tC9803D99D64F5D893C71690F4B65415B86B42629_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteralE514E1AE1B1F65BD7549E260248926108E125A19;
IL2CPP_EXTERN_C const RuntimeMethod* Contour_FindPointInPolygon_m1EA0F170F9981733E20CD3F51393CCE8AE646A90_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_AddRange_m36112548B1DAAA54724D07790D3870E097280A93_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_AddRange_mE6E8EB92058F5D3CE0D7C8F8F704530F831AB73F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mA8954CBD8FEAD083744D6ED57632DA1748BB6219_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mDF33EBADE6B533124F05BADC13B657B09BA0A931_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_RemoveAt_m8984E8CB7741AB4B269535BB2022B96626DEA731_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m0F779156FD1338918FE0F75C38BB5F125B2481FD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m68BD43D8AF63E49A99553383E9C858443D6DA7E0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m727631CEA562FE331684A8FEB77B31AAAFF8EA5F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_mB6A622E23FCC654DEFEF1E7782145EC90D05592C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_mE9B028637F05103882B499E0D71BB1C14F2F5382_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Segment_GetTriangle_m899F4C9637B3F2F5C91DC5EE4494DC2B96BE0C6E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Segment_GetVertex_m6C0556367EEAF733310FAC17B5A25FC9C9F9186E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Vertex_get_Item_mD277E990CF8ABA774434CFC508638CEEF54458CE_RuntimeMethod_var;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment>
struct List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ISegmentU5BU5D_tBE0FE4A4777ED9BC3C74FA1CBA973A2FDC34875D* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<TriangleNet.Geometry.Point>
struct List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	PointU5BU5D_t4457033206B94B24EC4BDD2BF511DC9BE9379E17* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<TriangleNet.Geometry.RegionPointer>
struct List_1_tC9803D99D64F5D893C71690F4B65415B86B42629  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	RegionPointerU5BU5D_t1A7AF98468D2FEF4F1A3F9D12E8526B12E13B396* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>
struct List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C  : public RuntimeObject
{
	// T[] System.Collections.Generic.List`1::_items
	VertexU5BU5D_t02C037B0D0EC7CCCC8569ACFA81923FC98A27A06* ____items_1;
	// System.Int32 System.Collections.Generic.List`1::_size
	int32_t ____size_2;
	// System.Int32 System.Collections.Generic.List`1::_version
	int32_t ____version_3;
	// System.Object System.Collections.Generic.List`1::_syncRoot
	RuntimeObject* ____syncRoot_4;
};

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_tDF76FE2002958A97429065AC028E0A0C70442121  : public RuntimeObject
{
};

// TriangleNet.Meshing.ConstraintOptions
struct ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC  : public RuntimeObject
{
	// System.Boolean TriangleNet.Meshing.ConstraintOptions::<UseRegions>k__BackingField
	bool ___U3CUseRegionsU3Ek__BackingField_0;
	// System.Boolean TriangleNet.Meshing.ConstraintOptions::<ConformingDelaunay>k__BackingField
	bool ___U3CConformingDelaunayU3Ek__BackingField_1;
	// System.Boolean TriangleNet.Meshing.ConstraintOptions::<Convex>k__BackingField
	bool ___U3CConvexU3Ek__BackingField_2;
	// System.Int32 TriangleNet.Meshing.ConstraintOptions::<SegmentSplitting>k__BackingField
	int32_t ___U3CSegmentSplittingU3Ek__BackingField_3;
};

// TriangleNet.Geometry.Contour
struct Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087  : public RuntimeObject
{
	// System.Int32 TriangleNet.Geometry.Contour::marker
	int32_t ___marker_0;
	// System.Boolean TriangleNet.Geometry.Contour::convex
	bool ___convex_1;
	// System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex> TriangleNet.Geometry.Contour::<Points>k__BackingField
	List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___U3CPointsU3Ek__BackingField_2;
};

// TriangleNet.Geometry.Edge
struct Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64  : public RuntimeObject
{
	// System.Int32 TriangleNet.Geometry.Edge::<P0>k__BackingField
	int32_t ___U3CP0U3Ek__BackingField_0;
	// System.Int32 TriangleNet.Geometry.Edge::<P1>k__BackingField
	int32_t ___U3CP1U3Ek__BackingField_1;
	// System.Int32 TriangleNet.Geometry.Edge::<Label>k__BackingField
	int32_t ___U3CLabelU3Ek__BackingField_2;
};

// TriangleNet.Geometry.ExtensionMethods
struct ExtensionMethods_tC78F8CD07B46DC4257F6EAE7211F8AB6C6D688AA  : public RuntimeObject
{
};

// TriangleNet.Meshing.GenericMesher
struct GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD  : public RuntimeObject
{
	// TriangleNet.Configuration TriangleNet.Meshing.GenericMesher::config
	Configuration_t4555CC5B976EF0C0297F35B57FCB1BB5B656283A* ___config_0;
	// TriangleNet.Meshing.ITriangulator TriangleNet.Meshing.GenericMesher::triangulator
	RuntimeObject* ___triangulator_1;
};

// TriangleNet.Geometry.Point
struct Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1  : public RuntimeObject
{
	// System.Int32 TriangleNet.Geometry.Point::id
	int32_t ___id_0;
	// System.Int32 TriangleNet.Geometry.Point::label
	int32_t ___label_1;
	// System.Double TriangleNet.Geometry.Point::x
	double ___x_2;
	// System.Double TriangleNet.Geometry.Point::y
	double ___y_3;
};

// TriangleNet.Geometry.Polygon
struct Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2  : public RuntimeObject
{
	// System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex> TriangleNet.Geometry.Polygon::points
	List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___points_0;
	// System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment> TriangleNet.Geometry.Polygon::segments
	List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* ___segments_1;
	// System.Collections.Generic.List`1<TriangleNet.Geometry.Point> TriangleNet.Geometry.Polygon::holes
	List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE* ___holes_2;
	// System.Collections.Generic.List`1<TriangleNet.Geometry.RegionPointer> TriangleNet.Geometry.Polygon::regions
	List_1_tC9803D99D64F5D893C71690F4B65415B86B42629* ___regions_3;
	// System.Boolean TriangleNet.Geometry.Polygon::<HasPointMarkers>k__BackingField
	bool ___U3CHasPointMarkersU3Ek__BackingField_4;
	// System.Boolean TriangleNet.Geometry.Polygon::<HasSegmentMarkers>k__BackingField
	bool ___U3CHasSegmentMarkersU3Ek__BackingField_5;
};

// TriangleNet.Meshing.QualityOptions
struct QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E  : public RuntimeObject
{
	// System.Double TriangleNet.Meshing.QualityOptions::<MaximumAngle>k__BackingField
	double ___U3CMaximumAngleU3Ek__BackingField_0;
	// System.Double TriangleNet.Meshing.QualityOptions::<MinimumAngle>k__BackingField
	double ___U3CMinimumAngleU3Ek__BackingField_1;
	// System.Double TriangleNet.Meshing.QualityOptions::<MaximumArea>k__BackingField
	double ___U3CMaximumAreaU3Ek__BackingField_2;
	// System.Func`3<TriangleNet.Geometry.ITriangle,System.Double,System.Boolean> TriangleNet.Meshing.QualityOptions::<UserTest>k__BackingField
	Func_3_tE5672D52F7EAAC12E73F6D0A3AC6882EE3E6F2C3* ___U3CUserTestU3Ek__BackingField_3;
	// System.Func`2<TriangleNet.Geometry.ITriangle,System.Boolean> TriangleNet.Meshing.QualityOptions::<Exclude>k__BackingField
	Func_2_tDDCB4765EFB0E436EECCED6ABE46E3207BC68C63* ___U3CExcludeU3Ek__BackingField_4;
	// System.Boolean TriangleNet.Meshing.QualityOptions::<VariableArea>k__BackingField
	bool ___U3CVariableAreaU3Ek__BackingField_5;
	// System.Int32 TriangleNet.Meshing.QualityOptions::<SteinerPoints>k__BackingField
	int32_t ___U3CSteinerPointsU3Ek__BackingField_6;
	// System.Boolean TriangleNet.Meshing.QualityOptions::<UseLegacyRefinement>k__BackingField
	bool ___U3CUseLegacyRefinementU3Ek__BackingField_7;
};

// TriangleNet.Geometry.Rectangle
struct Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B  : public RuntimeObject
{
	// System.Double TriangleNet.Geometry.Rectangle::xmin
	double ___xmin_0;
	// System.Double TriangleNet.Geometry.Rectangle::ymin
	double ___ymin_1;
	// System.Double TriangleNet.Geometry.Rectangle::xmax
	double ___xmax_2;
	// System.Double TriangleNet.Geometry.Rectangle::ymax
	double ___ymax_3;
};

// TriangleNet.Geometry.RegionPointer
struct RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B  : public RuntimeObject
{
	// TriangleNet.Geometry.Point TriangleNet.Geometry.RegionPointer::<Point>k__BackingField
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___U3CPointU3Ek__BackingField_0;
	// System.Int32 TriangleNet.Geometry.RegionPointer::<Label>k__BackingField
	int32_t ___U3CLabelU3Ek__BackingField_1;
	// System.Double TriangleNet.Geometry.RegionPointer::<Area>k__BackingField
	double ___U3CAreaU3Ek__BackingField_2;
};

// TriangleNet.RobustPredicates
struct RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93  : public RuntimeObject
{
	// System.Double[] TriangleNet.RobustPredicates::fin1
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___fin1_11;
	// System.Double[] TriangleNet.RobustPredicates::fin2
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___fin2_12;
	// System.Double[] TriangleNet.RobustPredicates::abdet
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___abdet_13;
	// System.Double[] TriangleNet.RobustPredicates::axbc
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___axbc_14;
	// System.Double[] TriangleNet.RobustPredicates::axxbc
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___axxbc_15;
	// System.Double[] TriangleNet.RobustPredicates::aybc
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___aybc_16;
	// System.Double[] TriangleNet.RobustPredicates::ayybc
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___ayybc_17;
	// System.Double[] TriangleNet.RobustPredicates::adet
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___adet_18;
	// System.Double[] TriangleNet.RobustPredicates::bxca
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___bxca_19;
	// System.Double[] TriangleNet.RobustPredicates::bxxca
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___bxxca_20;
	// System.Double[] TriangleNet.RobustPredicates::byca
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___byca_21;
	// System.Double[] TriangleNet.RobustPredicates::byyca
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___byyca_22;
	// System.Double[] TriangleNet.RobustPredicates::bdet
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___bdet_23;
	// System.Double[] TriangleNet.RobustPredicates::cxab
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___cxab_24;
	// System.Double[] TriangleNet.RobustPredicates::cxxab
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___cxxab_25;
	// System.Double[] TriangleNet.RobustPredicates::cyab
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___cyab_26;
	// System.Double[] TriangleNet.RobustPredicates::cyyab
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___cyyab_27;
	// System.Double[] TriangleNet.RobustPredicates::cdet
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___cdet_28;
	// System.Double[] TriangleNet.RobustPredicates::temp8
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___temp8_29;
	// System.Double[] TriangleNet.RobustPredicates::temp16a
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___temp16a_30;
	// System.Double[] TriangleNet.RobustPredicates::temp16b
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___temp16b_31;
	// System.Double[] TriangleNet.RobustPredicates::temp16c
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___temp16c_32;
	// System.Double[] TriangleNet.RobustPredicates::temp32a
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___temp32a_33;
	// System.Double[] TriangleNet.RobustPredicates::temp32b
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___temp32b_34;
	// System.Double[] TriangleNet.RobustPredicates::temp48
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___temp48_35;
	// System.Double[] TriangleNet.RobustPredicates::temp64
	DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___temp64_36;
};

// TriangleNet.Geometry.Segment
struct Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E  : public RuntimeObject
{
	// TriangleNet.Geometry.Vertex TriangleNet.Geometry.Segment::v0
	Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* ___v0_0;
	// TriangleNet.Geometry.Vertex TriangleNet.Geometry.Segment::v1
	Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* ___v1_1;
	// System.Int32 TriangleNet.Geometry.Segment::<Label>k__BackingField
	int32_t ___U3CLabelU3Ek__BackingField_2;
};

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
};

// System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

// System.Double
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	// System.Double System.Double::m_value
	double ___m_value_0;
};

// System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
// Native definition for P/Invoke marshalling of System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.Int64
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	// System.Int64 System.Int64::m_value
	int64_t ___m_value_0;
};

// System.IntPtr
struct IntPtr_t 
{
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;
};

// TriangleNet.Topology.Otri
struct Otri_tF8EE8B45C5B51552194F461EA8B825BAF8CC1970 
{
	// TriangleNet.Topology.Triangle TriangleNet.Topology.Otri::tri
	Triangle_t1D943DC9E3293CDEE67259B7C9E1A2C8E09CF642* ___tri_0;
	// System.Int32 TriangleNet.Topology.Otri::orient
	int32_t ___orient_1;
};
// Native definition for P/Invoke marshalling of TriangleNet.Topology.Otri
struct Otri_tF8EE8B45C5B51552194F461EA8B825BAF8CC1970_marshaled_pinvoke
{
	Triangle_t1D943DC9E3293CDEE67259B7C9E1A2C8E09CF642* ___tri_0;
	int32_t ___orient_1;
};
// Native definition for COM marshalling of TriangleNet.Topology.Otri
struct Otri_tF8EE8B45C5B51552194F461EA8B825BAF8CC1970_marshaled_com
{
	Triangle_t1D943DC9E3293CDEE67259B7C9E1A2C8E09CF642* ___tri_0;
	int32_t ___orient_1;
};

// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=128
struct __StaticArrayInitTypeSizeU3D128_t75E02F90AEC23153A6D1796A18A23B07C03B38D1 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D128_t75E02F90AEC23153A6D1796A18A23B07C03B38D1__padding[128];
	};
};

// System.Exception
struct Exception_t  : public RuntimeObject
{
	// System.String System.Exception::_className
	String_t* ____className_1;
	// System.String System.Exception::_message
	String_t* ____message_2;
	// System.Collections.IDictionary System.Exception::_data
	RuntimeObject* ____data_3;
	// System.Exception System.Exception::_innerException
	Exception_t* ____innerException_4;
	// System.String System.Exception::_helpURL
	String_t* ____helpURL_5;
	// System.Object System.Exception::_stackTrace
	RuntimeObject* ____stackTrace_6;
	// System.String System.Exception::_stackTraceString
	String_t* ____stackTraceString_7;
	// System.String System.Exception::_remoteStackTraceString
	String_t* ____remoteStackTraceString_8;
	// System.Int32 System.Exception::_remoteStackIndex
	int32_t ____remoteStackIndex_9;
	// System.Object System.Exception::_dynamicMethods
	RuntimeObject* ____dynamicMethods_10;
	// System.Int32 System.Exception::_HResult
	int32_t ____HResult_11;
	// System.String System.Exception::_source
	String_t* ____source_12;
	// System.Runtime.Serialization.SafeSerializationManager System.Exception::_safeSerializationManager
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	// System.Diagnostics.StackTrace[] System.Exception::captured_traces
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	// System.IntPtr[] System.Exception::native_trace_ips
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips_15;
	// System.Int32 System.Exception::caught_in_unmanaged
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for P/Invoke marshalling of System.Exception
struct Exception_t_marshaled_pinvoke
{
	char* ____className_1;
	char* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_pinvoke* ____innerException_4;
	char* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	char* ____stackTraceString_7;
	char* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	char* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for COM marshalling of System.Exception
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className_1;
	Il2CppChar* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_com* ____innerException_4;
	Il2CppChar* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	Il2CppChar* ____stackTraceString_7;
	Il2CppChar* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	Il2CppChar* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};

// TriangleNet.VertexType
struct VertexType_t556AC7607D5543895654749843BE1EE3FF39E368 
{
	// System.Int32 TriangleNet.VertexType::value__
	int32_t ___value___2;
};

// System.SystemException
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};

// TriangleNet.Geometry.Vertex
struct Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A  : public Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1
{
	// System.Int32 TriangleNet.Geometry.Vertex::hash
	int32_t ___hash_4;
	// TriangleNet.VertexType TriangleNet.Geometry.Vertex::type
	int32_t ___type_5;
	// TriangleNet.Topology.Otri TriangleNet.Geometry.Vertex::tri
	Otri_tF8EE8B45C5B51552194F461EA8B825BAF8CC1970 ___tri_6;
};

// System.ArgumentException
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	// System.String System.ArgumentException::_paramName
	String_t* ____paramName_18;
};

// System.IndexOutOfRangeException
struct IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};

// System.NotImplementedException
struct NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};

// System.ArgumentOutOfRangeException
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
	// System.Object System.ArgumentOutOfRangeException::_actualValue
	RuntimeObject* ____actualValue_19;
};

// System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment>
struct List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ISegmentU5BU5D_tBE0FE4A4777ED9BC3C74FA1CBA973A2FDC34875D* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment>

// System.Collections.Generic.List`1<System.Object>
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<System.Object>

// System.Collections.Generic.List`1<TriangleNet.Geometry.Point>
struct List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	PointU5BU5D_t4457033206B94B24EC4BDD2BF511DC9BE9379E17* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<TriangleNet.Geometry.Point>

// System.Collections.Generic.List`1<TriangleNet.Geometry.RegionPointer>
struct List_1_tC9803D99D64F5D893C71690F4B65415B86B42629_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	RegionPointerU5BU5D_t1A7AF98468D2FEF4F1A3F9D12E8526B12E13B396* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<TriangleNet.Geometry.RegionPointer>

// System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>
struct List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C_StaticFields
{
	// T[] System.Collections.Generic.List`1::s_emptyArray
	VertexU5BU5D_t02C037B0D0EC7CCCC8569ACFA81923FC98A27A06* ___s_emptyArray_5;
};

// System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_tDF76FE2002958A97429065AC028E0A0C70442121_StaticFields
{
	// System.Int32 <PrivateImplementationDetails>::4E225601A48925147F919ACEAC44E7ADAE64F8E5FBAB35D1AE0B189A6047459D
	int32_t ___4E225601A48925147F919ACEAC44E7ADAE64F8E5FBAB35D1AE0B189A6047459D_0;
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=128 <PrivateImplementationDetails>::B1E987986879E247BFBD6E53C6EA49FEE1EA0ADF603D05149E1DB7815D3585DE
	__StaticArrayInitTypeSizeU3D128_t75E02F90AEC23153A6D1796A18A23B07C03B38D1 ___B1E987986879E247BFBD6E53C6EA49FEE1EA0ADF603D05149E1DB7815D3585DE_1;
};

// <PrivateImplementationDetails>

// TriangleNet.Meshing.ConstraintOptions

// TriangleNet.Meshing.ConstraintOptions

// TriangleNet.Geometry.Contour

// TriangleNet.Geometry.Contour

// TriangleNet.Geometry.Edge

// TriangleNet.Geometry.Edge

// TriangleNet.Geometry.ExtensionMethods

// TriangleNet.Geometry.ExtensionMethods

// TriangleNet.Meshing.GenericMesher

// TriangleNet.Meshing.GenericMesher

// TriangleNet.Geometry.Point

// TriangleNet.Geometry.Point

// TriangleNet.Geometry.Polygon

// TriangleNet.Geometry.Polygon

// TriangleNet.Meshing.QualityOptions

// TriangleNet.Meshing.QualityOptions

// TriangleNet.Geometry.Rectangle

// TriangleNet.Geometry.Rectangle

// TriangleNet.Geometry.RegionPointer

// TriangleNet.Geometry.RegionPointer

// TriangleNet.RobustPredicates
struct RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93_StaticFields
{
	// System.Object TriangleNet.RobustPredicates::creationLock
	RuntimeObject* ___creationLock_0;
	// TriangleNet.RobustPredicates TriangleNet.RobustPredicates::_default
	RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93* ____default_1;
	// System.Double TriangleNet.RobustPredicates::epsilon
	double ___epsilon_2;
	// System.Double TriangleNet.RobustPredicates::splitter
	double ___splitter_3;
	// System.Double TriangleNet.RobustPredicates::resulterrbound
	double ___resulterrbound_4;
	// System.Double TriangleNet.RobustPredicates::ccwerrboundA
	double ___ccwerrboundA_5;
	// System.Double TriangleNet.RobustPredicates::ccwerrboundB
	double ___ccwerrboundB_6;
	// System.Double TriangleNet.RobustPredicates::ccwerrboundC
	double ___ccwerrboundC_7;
	// System.Double TriangleNet.RobustPredicates::iccerrboundA
	double ___iccerrboundA_8;
	// System.Double TriangleNet.RobustPredicates::iccerrboundB
	double ___iccerrboundB_9;
	// System.Double TriangleNet.RobustPredicates::iccerrboundC
	double ___iccerrboundC_10;
};

// TriangleNet.RobustPredicates

// TriangleNet.Geometry.Segment

// TriangleNet.Geometry.Segment

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Boolean

// System.Double

// System.Double

// System.Int32

// System.Int32

// System.Int64

// System.Int64

// System.Void

// System.Void

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=128

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=128

// System.Exception
struct Exception_t_StaticFields
{
	// System.Object System.Exception::s_EDILock
	RuntimeObject* ___s_EDILock_0;
};

// System.Exception

// TriangleNet.VertexType

// TriangleNet.VertexType

// TriangleNet.Geometry.Vertex

// TriangleNet.Geometry.Vertex

// System.IndexOutOfRangeException

// System.IndexOutOfRangeException

// System.NotImplementedException

// System.NotImplementedException

// System.ArgumentOutOfRangeException

// System.ArgumentOutOfRangeException
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


// System.Void System.Collections.Generic.List`1<System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// System.Int32 System.Collections.Generic.List`1<System.Object>::get_Count()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
// T System.Collections.Generic.List`1<System.Object>::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_get_Item_m33561245D64798C2AB07584C0EC4F240E4839A38_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::Add(T)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::.ctor(System.Collections.Generic.IEnumerable`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mE097DBD72433D1AFC11733F5678602603A756424_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::RemoveAt(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m76CBBC3E2F0583F5AD30CE592CEA1225C06A0428_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<System.Object>::AddRange(System.Collections.Generic.IEnumerable`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m1F76B300133150E6046C5FED00E88B5DE0A02E17_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) ;

// System.Void TriangleNet.Geometry.Contour::.ctor(System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Vertex>,System.Int32,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Contour__ctor_m17D124B8938DE69B9F8FF0AC1E29E17B0A998DA8 (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, RuntimeObject* ___0_points, int32_t ___1_marker, bool ___2_convex, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Contour::AddPoints(System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Vertex>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Contour_AddPoints_mA17BBAA10A91FDAE368D9124913CCB1A64B5EC7F (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, RuntimeObject* ___0_points, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment>::.ctor()
inline void List_1__ctor_mB6A622E23FCC654DEFEF1E7782145EC90D05592C (List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex> TriangleNet.Geometry.Contour::get_Points()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07_inline (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, const RuntimeMethod* method) ;
// System.Int32 System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>::get_Count()
inline int32_t List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_inline (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C*, const RuntimeMethod*))List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline)(__this, method);
}
// T System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>::get_Item(System.Int32)
inline Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* (*) (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C*, int32_t, const RuntimeMethod*))List_1_get_Item_m33561245D64798C2AB07584C0EC4F240E4839A38_gshared)(__this, ___0_index, method);
}
// System.Void TriangleNet.Geometry.Segment::.ctor(TriangleNet.Geometry.Vertex,TriangleNet.Geometry.Vertex,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Segment__ctor_mDC03832F4F3F9FDC8C8F8EFAE7B86DA5579DB0DF (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* ___0_v0, Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* ___1_v1, int32_t ___2_label, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment>::Add(T)
inline void List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_inline (List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* __this, RuntimeObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431*, RuntimeObject*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Void TriangleNet.Geometry.Point::.ctor(System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Point__ctor_m36BE66184AB548B99409ADDD4178D0019D4E0289 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, double ___0_x, double ___1_y, const RuntimeMethod* method) ;
// TriangleNet.Geometry.Point TriangleNet.Geometry.Contour::FindPointInPolygon(System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>,System.Int32,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* Contour_FindPointInPolygon_m1EA0F170F9981733E20CD3F51393CCE8AE646A90 (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___0_contour, int32_t ___1_limit, double ___2_eps, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>::.ctor(System.Collections.Generic.IEnumerable`1<T>)
inline void List_1__ctor_m68BD43D8AF63E49A99553383E9C858443D6DA7E0 (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method)
{
	((  void (*) (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C*, RuntimeObject*, const RuntimeMethod*))List_1__ctor_mE097DBD72433D1AFC11733F5678602603A756424_gshared)(__this, ___0_collection, method);
}
// System.Void TriangleNet.Geometry.Contour::set_Points(System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Contour_set_Points_mBA0FAB674F747150769FB8A1FB62D129A1ED3179_inline (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___0_value, const RuntimeMethod* method) ;
// System.Boolean TriangleNet.Geometry.Point::op_Equality(TriangleNet.Geometry.Point,TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Point_op_Equality_m130AAFCC6C0C4CD8FD648741E55C3B7806E4AD0F (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_a, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___1_b, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>::RemoveAt(System.Int32)
inline void List_1_RemoveAt_m8984E8CB7741AB4B269535BB2022B96626DEA731 (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C*, int32_t, const RuntimeMethod*))List_1_RemoveAt_m54F62297ADEE4D4FDA697F49ED807BF901201B54_gshared)(__this, ___0_index, method);
}
// System.Void TriangleNet.Geometry.Rectangle::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle__ctor_m826E64394C092D2A9D743261E2A10E22F9697FD6 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Rectangle::Expand(System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Point>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle_Expand_m866BD091569A256E1E06FC3E6B3627DFC125FDD7 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, RuntimeObject* ___0_points, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Point::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Point__ctor_m4B0499A60884D4097A6297F5755770AC1A7378BF (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) ;
// TriangleNet.RobustPredicates TriangleNet.RobustPredicates::get_Default()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93* RobustPredicates_get_Default_m2B50082A2EFA9EFD0BF54BD5BF6416A0F543BC67 (const RuntimeMethod* method) ;
// System.Double TriangleNet.RobustPredicates::CounterClockwise(TriangleNet.Geometry.Point,TriangleNet.Geometry.Point,TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double RobustPredicates_CounterClockwise_m0E246DE9FDFC1A66F6584A724BE62B281FEEFF86 (RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_pa, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___1_pb, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___2_pc, const RuntimeMethod* method) ;
// System.Boolean TriangleNet.Geometry.Rectangle::Contains(TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Rectangle_Contains_mE8BE1E8DFEBE3EF1784CFCFB3C93DF2809A87197 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_pt, const RuntimeMethod* method) ;
// System.Boolean TriangleNet.Geometry.Contour::IsPointInPolygon(TriangleNet.Geometry.Point,System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Contour_IsPointInPolygon_m853A279C7C310A76B85394F9665622BCD0F50430 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_point, List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___1_poly, const RuntimeMethod* method) ;
// System.Boolean TriangleNet.Geometry.Contour::IsPointOnSegment(TriangleNet.Geometry.Point,System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Contour_IsPointOnSegment_m66D26E3455C2BC85A86186BA4D0B629A080A21BE (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_test, List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___1_contour, double ___2_eps, const RuntimeMethod* method) ;
// System.Void System.Exception::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Exception__ctor_m203319D1EA1274689B380A947B4ADC8445662B8F (Exception_t* __this, const RuntimeMethod* method) ;
// System.Boolean TriangleNet.Tools.IntersectionHelper::IsPointOnSegment(TriangleNet.Geometry.Point,TriangleNet.Geometry.Point,TriangleNet.Geometry.Point,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IntersectionHelper_IsPointOnSegment_m3FEC4A8E81EEE58DCBBFFE1215AB997EBF5B95DC (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_a, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___1_b, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___2_test, double ___3_eps, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Edge::.ctor(System.Int32,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Edge__ctor_m357B4ED93E3E0F66F877FADCCB920FE114649073 (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_p0, int32_t ___1_p1, int32_t ___2_label, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Edge::set_P0(System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Edge_set_P0_mB0616BBD1AF6210443FF8BF3F3C81F9DDC5728EA_inline (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Edge::set_P1(System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Edge_set_P1_m35B336CD05909FEEE165A4FF77DCDF554D0653E5_inline (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Edge::set_Label(System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Edge_set_Label_m2CCB72689E3B178FC25C8BDDEC3334E1D3FF101F_inline (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void TriangleNet.Meshing.GenericMesher::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GenericMesher__ctor_m77E9F21C2EA55F5B700657945CD08839C46D25D5 (GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD* __this, const RuntimeMethod* method) ;
// TriangleNet.Meshing.IMesh TriangleNet.Meshing.GenericMesher::Triangulate(TriangleNet.Geometry.IPolygon,TriangleNet.Meshing.ConstraintOptions,TriangleNet.Meshing.QualityOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GenericMesher_Triangulate_m3320114AB3BE6550F20D671A006B1F9C4E715E8C (GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD* __this, RuntimeObject* ___0_polygon, ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC* ___1_options, QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E* ___2_quality, const RuntimeMethod* method) ;
// System.Void TriangleNet.Meshing.GenericMesher::.ctor(TriangleNet.Meshing.ITriangulator)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GenericMesher__ctor_mC1CE60AA43F1A3BC515E5B4BAE56B54701842B3F (GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD* __this, RuntimeObject* ___0_triangulator, const RuntimeMethod* method) ;
// System.Double TriangleNet.Geometry.Point::get_X()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) ;
// System.Double TriangleNet.Geometry.Point::get_Y()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) ;
// System.Boolean TriangleNet.Geometry.ExtensionMethods::Contains(TriangleNet.Geometry.ITriangle,System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ExtensionMethods_Contains_m2DA8B67B73946251BF8263413FCE93A0AC2D70FA (RuntimeObject* ___0_triangle, double ___1_x, double ___2_y, const RuntimeMethod* method) ;
// System.Double TriangleNet.Geometry.ExtensionMethods::DotProduct(TriangleNet.Geometry.Point,TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double ExtensionMethods_DotProduct_m4462CDC92CEC0443C86DAD5484D3E9FAAE2DB58B (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_p, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___1_q, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Rectangle::Expand(TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle_Expand_mB0DC57451EAFE5F38DAAB3C29CBD577977A4200B (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_p, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Point::.ctor(System.Double,System.Double,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Point__ctor_m6F9D396D184EC6C20BF40C449AB7964256A0C863 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, double ___0_x, double ___1_y, int32_t ___2_label, const RuntimeMethod* method) ;
// System.Boolean TriangleNet.Geometry.Point::Equals(TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Point_Equals_mBC8DC476D701493987584DCC813F8CEA1E68C59E (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_p, const RuntimeMethod* method) ;
// System.Int32 System.Double::GetHashCode()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline (double* __this, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Polygon::.ctor(System.Int32,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon__ctor_mE632B4B8B90E7934A628A8D2459122EB1F00BF89 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, int32_t ___0_capacity, bool ___1_markers, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>::.ctor(System.Int32)
inline void List_1__ctor_mE9B028637F05103882B499E0D71BB1C14F2F5382 (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	((  void (*) (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C*, int32_t, const RuntimeMethod*))List_1__ctor_m76CBBC3E2F0583F5AD30CE592CEA1225C06A0428_gshared)(__this, ___0_capacity, method);
}
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.Point>::.ctor()
inline void List_1__ctor_m727631CEA562FE331684A8FEB77B31AAAFF8EA5F (List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.RegionPointer>::.ctor()
inline void List_1__ctor_m0F779156FD1338918FE0F75C38BB5F125B2481FD (List_1_tC9803D99D64F5D893C71690F4B65415B86B42629* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tC9803D99D64F5D893C71690F4B65415B86B42629*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
// System.Void TriangleNet.Geometry.Polygon::set_HasPointMarkers(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Polygon_set_HasPointMarkers_m18685DE71EEBCC7E72D83FBDF5B812610C25E51A_inline (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Polygon::set_HasSegmentMarkers(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Polygon_set_HasSegmentMarkers_mCCFDDD29B78E8945420060057599DA63DB064B38_inline (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>::Add(T)
inline void List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_inline (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* __this, Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C*, Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>::AddRange(System.Collections.Generic.IEnumerable`1<T>)
inline void List_1_AddRange_mE6E8EB92058F5D3CE0D7C8F8F704530F831AB73F (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method)
{
	((  void (*) (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C*, RuntimeObject*, const RuntimeMethod*))List_1_AddRange_m1F76B300133150E6046C5FED00E88B5DE0A02E17_gshared)(__this, ___0_collection, method);
}
// System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment> TriangleNet.Geometry.Contour::GetSegments()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* Contour_GetSegments_m64CB26CBBFADDF36C3DF408568481DCAA624DDEF (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment>::AddRange(System.Collections.Generic.IEnumerable`1<T>)
inline void List_1_AddRange_m36112548B1DAAA54724D07790D3870E097280A93 (List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method)
{
	((  void (*) (List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431*, RuntimeObject*, const RuntimeMethod*))List_1_AddRange_m1F76B300133150E6046C5FED00E88B5DE0A02E17_gshared)(__this, ___0_collection, method);
}
// TriangleNet.Geometry.Point TriangleNet.Geometry.Contour::FindInteriorPoint(System.Int32,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* Contour_FindInteriorPoint_m405B8515C17A404A24B40398F1390C050BE380B1 (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, int32_t ___0_limit, double ___1_eps, const RuntimeMethod* method) ;
// System.Collections.Generic.List`1<TriangleNet.Geometry.RegionPointer> TriangleNet.Geometry.Polygon::get_Regions()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR List_1_tC9803D99D64F5D893C71690F4B65415B86B42629* Polygon_get_Regions_m660FF6A0859225FB2AAC663ED02B6679B866CC43_inline (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.RegionPointer::.ctor(System.Double,System.Double,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RegionPointer__ctor_mAFFA818BD752BBEDF313C606A15989706779A45B (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, double ___0_x, double ___1_y, int32_t ___2_label, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.RegionPointer>::Add(T)
inline void List_1_Add_mDF33EBADE6B533124F05BADC13B657B09BA0A931_inline (List_1_tC9803D99D64F5D893C71690F4B65415B86B42629* __this, RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tC9803D99D64F5D893C71690F4B65415B86B42629*, RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Void TriangleNet.Geometry.Polygon::AddContourPointsAndSegments(TriangleNet.Geometry.Contour)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_AddContourPointsAndSegments_m1C3789D2CF4448291C1335664C7B2BE9E11DCA8B (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* ___0_contour, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Polygon::Add(TriangleNet.Geometry.Contour,TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_Add_mB07D1D1781C87FCDEC98322A9804357826BE7F67 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* ___0_contour, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___1_hole, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.List`1<TriangleNet.Geometry.Point>::Add(T)
inline void List_1_Add_mA8954CBD8FEAD083744D6ED57632DA1748BB6219_inline (List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE*, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
// System.Double TriangleNet.Geometry.Rectangle::get_Left()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Rectangle_get_Left_mD51F75017ABFAB864FCFFA000654BAD8B69C0095_inline (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) ;
// System.Double TriangleNet.Geometry.Rectangle::get_Bottom()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Rectangle_get_Bottom_m50E053BB79DB47EACE3D76FCB9B9838691C831FC_inline (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) ;
// System.Double TriangleNet.Geometry.Rectangle::get_Right()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Rectangle_get_Right_m66D5AC49665B4ACF7E583D0DB180067C7275343D_inline (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) ;
// System.Double TriangleNet.Geometry.Rectangle::get_Top()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Rectangle_get_Top_mB5BBC0F6EF84C1DA34190080747C466F1465E64A_inline (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Rectangle::.ctor(System.Double,System.Double,System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle__ctor_mA1636D5D1554237F24B5FCBE65092D98F85CC53D (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, double ___0_x, double ___1_y, double ___2_width, double ___3_height, const RuntimeMethod* method) ;
// System.Double System.Math::Min(System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Math_Min_mA3310F1FF7876DA2FC7F37B822E6DD66410565C1 (double ___0_val1, double ___1_val2, const RuntimeMethod* method) ;
// System.Double System.Math::Max(System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Math_Max_m7BAC743E1752A51F258BB82DEBDD13E7C6D3ED26 (double ___0_val1, double ___1_val2, const RuntimeMethod* method) ;
// System.Boolean TriangleNet.Geometry.Rectangle::Contains(System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Rectangle_Contains_m9F847EC58CA335E2B9B453C6DD39604C8E903232 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, double ___0_x, double ___1_y, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.RegionPointer::.ctor(System.Double,System.Double,System.Int32,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RegionPointer__ctor_mB49AB58BE1A3D3F40469BA9F733C76D2E826A40A (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, double ___0_x, double ___1_y, int32_t ___2_label, double ___3_area, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.RegionPointer::set_Point(TriangleNet.Geometry.Point)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RegionPointer_set_Point_m16F2E59D9B4E72763D33C77452AFB4504607403F_inline (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_value, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.RegionPointer::set_Label(System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RegionPointer_set_Label_mCF3674DA129C2F8F5B943A496E2696664CF17235_inline (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.RegionPointer::set_Area(System.Double)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RegionPointer_set_Area_mEA8344CA85F6CD0E5FBF6B013692B653F48782A7_inline (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, double ___0_value, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Segment::set_Label(System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Segment_set_Label_mD44E71611259407699FE53DC530AD01E9F25FC79_inline (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void System.IndexOutOfRangeException::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexOutOfRangeException__ctor_m270ED9671475CE680EEA8C62A7A43308AE4188EF (IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82* __this, const RuntimeMethod* method) ;
// System.Void System.NotImplementedException::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotImplementedException__ctor_mDAB47BC6BD0E342E8F2171E5CABE3E67EA049F1C (NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8* __this, const RuntimeMethod* method) ;
// System.Void TriangleNet.Geometry.Vertex::.ctor(System.Double,System.Double,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vertex__ctor_mF5813341873B36A8E49E6030D2ED1A55073FE545 (Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* __this, double ___0_x, double ___1_y, int32_t ___2_mark, const RuntimeMethod* method) ;
// System.Void System.ArgumentOutOfRangeException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
// System.Int64 System.BitConverter::DoubleToInt64Bits(System.Double)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t BitConverter_DoubleToInt64Bits_m4F42741818550F9956B5FBAF88C051F4DE5B0AE6_inline (double ___0_value, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex> TriangleNet.Geometry.Contour::get_Points()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07 (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, const RuntimeMethod* method) 
{
	{
		// public List<Vertex> Points { get; set; }
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_0 = __this->___U3CPointsU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Contour::set_Points(System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Contour_set_Points_mBA0FAB674F747150769FB8A1FB62D129A1ED3179 (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___0_value, const RuntimeMethod* method) 
{
	{
		// public List<Vertex> Points { get; set; }
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_0 = ___0_value;
		__this->___U3CPointsU3Ek__BackingField_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CPointsU3Ek__BackingField_2), (void*)L_0);
		return;
	}
}
// System.Void TriangleNet.Geometry.Contour::.ctor(System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Vertex>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Contour__ctor_mD9E13D87772E471355994ADA9E0F450DD49EB748 (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, RuntimeObject* ___0_points, const RuntimeMethod* method) 
{
	{
		// : this(points, 0, false)
		RuntimeObject* L_0 = ___0_points;
		Contour__ctor_m17D124B8938DE69B9F8FF0AC1E29E17B0A998DA8(__this, L_0, 0, (bool)0, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Contour::.ctor(System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Vertex>,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Contour__ctor_mB8A64EA9D79C628AE75954E1EC566EBB2C8330AB (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, RuntimeObject* ___0_points, int32_t ___1_marker, const RuntimeMethod* method) 
{
	{
		// : this(points, marker, false)
		RuntimeObject* L_0 = ___0_points;
		int32_t L_1 = ___1_marker;
		Contour__ctor_m17D124B8938DE69B9F8FF0AC1E29E17B0A998DA8(__this, L_0, L_1, (bool)0, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Contour::.ctor(System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Vertex>,System.Int32,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Contour__ctor_m17D124B8938DE69B9F8FF0AC1E29E17B0A998DA8 (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, RuntimeObject* ___0_points, int32_t ___1_marker, bool ___2_convex, const RuntimeMethod* method) 
{
	{
		// public Contour(IEnumerable<Vertex> points, int marker, bool convex)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// AddPoints(points);
		RuntimeObject* L_0 = ___0_points;
		Contour_AddPoints_mA17BBAA10A91FDAE368D9124913CCB1A64B5EC7F(__this, L_0, NULL);
		// this.marker = marker;
		int32_t L_1 = ___1_marker;
		__this->___marker_0 = L_1;
		// this.convex = convex;
		bool L_2 = ___2_convex;
		__this->___convex_1 = L_2;
		// }
		return;
	}
}
// System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment> TriangleNet.Geometry.Contour::GetSegments()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* Contour_GetSegments_m64CB26CBBFADDF36C3DF408568481DCAA624DDEF (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mB6A622E23FCC654DEFEF1E7782145EC90D05592C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* V_0 = NULL;
	List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	{
		// var segments = new List<ISegment>();
		List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* L_0 = (List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431*)il2cpp_codegen_object_new(List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		List_1__ctor_mB6A622E23FCC654DEFEF1E7782145EC90D05592C(L_0, List_1__ctor_mB6A622E23FCC654DEFEF1E7782145EC90D05592C_RuntimeMethod_var);
		V_0 = L_0;
		// var p = Points;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_1;
		L_1 = Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07_inline(__this, NULL);
		V_1 = L_1;
		// int count = p.Count - 1;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_2 = V_1;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_inline(L_2, List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		V_2 = ((int32_t)il2cpp_codegen_subtract(L_3, 1));
		// for (int i = 0; i < count; i++)
		V_3 = 0;
		goto IL_003f;
	}

IL_001a:
	{
		// segments.Add(new Segment(p[i], p[i + 1], marker));
		List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* L_4 = V_0;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_5 = V_1;
		int32_t L_6 = V_3;
		NullCheck(L_5);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_7;
		L_7 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_5, L_6, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_8 = V_1;
		int32_t L_9 = V_3;
		NullCheck(L_8);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_10;
		L_10 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_8, ((int32_t)il2cpp_codegen_add(L_9, 1)), List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		int32_t L_11 = __this->___marker_0;
		Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* L_12 = (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E*)il2cpp_codegen_object_new(Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E_il2cpp_TypeInfo_var);
		NullCheck(L_12);
		Segment__ctor_mDC03832F4F3F9FDC8C8F8EFAE7B86DA5579DB0DF(L_12, L_7, L_10, L_11, NULL);
		NullCheck(L_4);
		List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_inline(L_4, L_12, List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_RuntimeMethod_var);
		// for (int i = 0; i < count; i++)
		int32_t L_13 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_003f:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_14 = V_3;
		int32_t L_15 = V_2;
		if ((((int32_t)L_14) < ((int32_t)L_15)))
		{
			goto IL_001a;
		}
	}
	{
		// segments.Add(new Segment(p[count], p[0], marker));
		List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* L_16 = V_0;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_17 = V_1;
		int32_t L_18 = V_2;
		NullCheck(L_17);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_19;
		L_19 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_17, L_18, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_20 = V_1;
		NullCheck(L_20);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_21;
		L_21 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_20, 0, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		int32_t L_22 = __this->___marker_0;
		Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* L_23 = (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E*)il2cpp_codegen_object_new(Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E_il2cpp_TypeInfo_var);
		NullCheck(L_23);
		Segment__ctor_mDC03832F4F3F9FDC8C8F8EFAE7B86DA5579DB0DF(L_23, L_19, L_21, L_22, NULL);
		NullCheck(L_16);
		List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_inline(L_16, L_23, List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_RuntimeMethod_var);
		// return segments;
		List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* L_24 = V_0;
		return L_24;
	}
}
// TriangleNet.Geometry.Point TriangleNet.Geometry.Contour::FindInteriorPoint(System.Int32,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* Contour_FindInteriorPoint_m405B8515C17A404A24B40398F1390C050BE380B1 (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, int32_t ___0_limit, double ___1_eps, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* V_0 = NULL;
	int32_t V_1 = 0;
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_2 = NULL;
	int32_t V_3 = 0;
	{
		// if (convex)
		bool L_0 = __this->___convex_1;
		if (!L_0)
		{
			goto IL_008f;
		}
	}
	{
		// var p = Points;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_1;
		L_1 = Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07_inline(__this, NULL);
		V_0 = L_1;
		// int count = p.Count;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_2 = V_0;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_inline(L_2, List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		V_1 = L_3;
		// var point = new Point(0.0, 0.0);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_4 = (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)il2cpp_codegen_object_new(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		Point__ctor_m36BE66184AB548B99409ADDD4178D0019D4E0289(L_4, (0.0), (0.0), NULL);
		V_2 = L_4;
		// for (int i = 0; i < count; i++)
		V_3 = 0;
		goto IL_006b;
	}

IL_0035:
	{
		// point.x += p[i].x;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_5 = V_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_6 = L_5;
		NullCheck(L_6);
		double L_7 = L_6->___x_2;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_8 = V_0;
		int32_t L_9 = V_3;
		NullCheck(L_8);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_10;
		L_10 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_8, L_9, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_10);
		double L_11 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_10)->___x_2;
		NullCheck(L_6);
		L_6->___x_2 = ((double)il2cpp_codegen_add(L_7, L_11));
		// point.y += p[i].y;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_12 = V_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_13 = L_12;
		NullCheck(L_13);
		double L_14 = L_13->___y_3;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_15 = V_0;
		int32_t L_16 = V_3;
		NullCheck(L_15);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_17;
		L_17 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_15, L_16, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_17);
		double L_18 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_17)->___y_3;
		NullCheck(L_13);
		L_13->___y_3 = ((double)il2cpp_codegen_add(L_14, L_18));
		// for (int i = 0; i < count; i++)
		int32_t L_19 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_006b:
	{
		// for (int i = 0; i < count; i++)
		int32_t L_20 = V_3;
		int32_t L_21 = V_1;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_0035;
		}
	}
	{
		// point.x /= count;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_22 = V_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_23 = L_22;
		NullCheck(L_23);
		double L_24 = L_23->___x_2;
		int32_t L_25 = V_1;
		NullCheck(L_23);
		L_23->___x_2 = ((double)(L_24/((double)L_25)));
		// point.y /= count;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_26 = V_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_27 = L_26;
		NullCheck(L_27);
		double L_28 = L_27->___y_3;
		int32_t L_29 = V_1;
		NullCheck(L_27);
		L_27->___y_3 = ((double)(L_28/((double)L_29)));
		// return point;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_30 = V_2;
		return L_30;
	}

IL_008f:
	{
		// return FindPointInPolygon(this.Points, limit, eps);
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_31;
		L_31 = Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07_inline(__this, NULL);
		int32_t L_32 = ___0_limit;
		double L_33 = ___1_eps;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_34;
		L_34 = Contour_FindPointInPolygon_m1EA0F170F9981733E20CD3F51393CCE8AE646A90(L_31, L_32, L_33, NULL);
		return L_34;
	}
}
// System.Void TriangleNet.Geometry.Contour::AddPoints(System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Vertex>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Contour_AddPoints_mA17BBAA10A91FDAE368D9124913CCB1A64B5EC7F (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, RuntimeObject* ___0_points, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_RemoveAt_m8984E8CB7741AB4B269535BB2022B96626DEA731_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m68BD43D8AF63E49A99553383E9C858443D6DA7E0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// Points = new List<Vertex>(points);
		RuntimeObject* L_0 = ___0_points;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_1 = (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C*)il2cpp_codegen_object_new(List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		List_1__ctor_m68BD43D8AF63E49A99553383E9C858443D6DA7E0(L_1, L_0, List_1__ctor_m68BD43D8AF63E49A99553383E9C858443D6DA7E0_RuntimeMethod_var);
		Contour_set_Points_mBA0FAB674F747150769FB8A1FB62D129A1ED3179_inline(__this, L_1, NULL);
		// int count = Points.Count - 1;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_2;
		L_2 = Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07_inline(__this, NULL);
		NullCheck(L_2);
		int32_t L_3;
		L_3 = List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_inline(L_2, List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_3, 1));
		// if (Points[0] == Points[count])
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_4;
		L_4 = Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07_inline(__this, NULL);
		NullCheck(L_4);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_5;
		L_5 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_4, 0, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_6;
		L_6 = Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07_inline(__this, NULL);
		int32_t L_7 = V_0;
		NullCheck(L_6);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_8;
		L_8 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_6, L_7, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		bool L_9;
		L_9 = Point_op_Equality_m130AAFCC6C0C4CD8FD648741E55C3B7806E4AD0F(L_5, L_8, NULL);
		if (!L_9)
		{
			goto IL_0045;
		}
	}
	{
		// Points.RemoveAt(count);
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_10;
		L_10 = Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07_inline(__this, NULL);
		int32_t L_11 = V_0;
		NullCheck(L_10);
		List_1_RemoveAt_m8984E8CB7741AB4B269535BB2022B96626DEA731(L_10, L_11, List_1_RemoveAt_m8984E8CB7741AB4B269535BB2022B96626DEA731_RuntimeMethod_var);
	}

IL_0045:
	{
		// }
		return;
	}
}
// TriangleNet.Geometry.Point TriangleNet.Geometry.Contour::FindPointInPolygon(System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>,System.Int32,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* Contour_FindPointInPolygon_m1EA0F170F9981733E20CD3F51393CCE8AE646A90 (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___0_contour, int32_t ___1_limit, double ___2_eps, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* V_0 = NULL;
	int32_t V_1 = 0;
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_2 = NULL;
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_3 = NULL;
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_4 = NULL;
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_5 = NULL;
	double V_6 = 0.0;
	double V_7 = 0.0;
	double V_8 = 0.0;
	double V_9 = 0.0;
	double V_10 = 0.0;
	RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93* V_11 = NULL;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	{
		// var bounds = new Rectangle();
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_0 = (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B*)il2cpp_codegen_object_new(Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Rectangle__ctor_m826E64394C092D2A9D743261E2A10E22F9697FD6(L_0, NULL);
		V_0 = L_0;
		// bounds.Expand(contour);
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_1 = V_0;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_2 = ___0_contour;
		NullCheck(L_1);
		Rectangle_Expand_m866BD091569A256E1E06FC3E6B3627DFC125FDD7(L_1, L_2, NULL);
		// int length = contour.Count;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_3 = ___0_contour;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_inline(L_3, List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		V_1 = L_4;
		// var test = new Point();
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_5 = (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)il2cpp_codegen_object_new(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		Point__ctor_m4B0499A60884D4097A6297F5755770AC1A7378BF(L_5, NULL);
		V_2 = L_5;
		// var predicates = RobustPredicates.Default;
		il2cpp_codegen_runtime_class_init_inline(RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93_il2cpp_TypeInfo_var);
		RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93* L_6;
		L_6 = RobustPredicates_get_Default_m2B50082A2EFA9EFD0BF54BD5BF6416A0F543BC67(NULL);
		V_11 = L_6;
		// a = contour[0];
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_7 = ___0_contour;
		NullCheck(L_7);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_8;
		L_8 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_7, 0, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		V_3 = L_8;
		// b = contour[1];
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_9 = ___0_contour;
		NullCheck(L_9);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_10;
		L_10 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_9, 1, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		V_4 = L_10;
		// for (int i = 0; i < length; i++)
		V_12 = 0;
		goto IL_01a2;
	}

IL_003a:
	{
		// c = contour[(i + 2) % length];
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_11 = ___0_contour;
		int32_t L_12 = V_12;
		int32_t L_13 = V_1;
		NullCheck(L_11);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_14;
		L_14 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_11, ((int32_t)(((int32_t)il2cpp_codegen_add(L_12, 2))%L_13)), List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		V_5 = L_14;
		// bx = b.x;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_15 = V_4;
		NullCheck(L_15);
		double L_16 = L_15->___x_2;
		V_6 = L_16;
		// by = b.y;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_17 = V_4;
		NullCheck(L_17);
		double L_18 = L_17->___y_3;
		V_7 = L_18;
		// h = predicates.CounterClockwise(a, b, c);
		RobustPredicates_t917807C8C5073A8CACCD08ED12D1FB2791AF6C93* L_19 = V_11;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_20 = V_3;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_21 = V_4;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_22 = V_5;
		NullCheck(L_19);
		double L_23;
		L_23 = RobustPredicates_CounterClockwise_m0E246DE9FDFC1A66F6584A724BE62B281FEEFF86(L_19, L_20, L_21, L_22, NULL);
		V_10 = L_23;
		// if (Math.Abs(h) < eps)
		double L_24 = V_10;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_25;
		L_25 = fabs(L_24);
		double L_26 = ___2_eps;
		if ((!(((double)L_25) < ((double)L_26))))
		{
			goto IL_00a8;
		}
	}
	{
		// dx = (c.y - a.y) / 2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_27 = V_5;
		NullCheck(L_27);
		double L_28 = L_27->___y_3;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_29 = V_3;
		NullCheck(L_29);
		double L_30 = L_29->___y_3;
		V_8 = ((double)(((double)il2cpp_codegen_subtract(L_28, L_30))/(2.0)));
		// dy = (a.x - c.x) / 2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_31 = V_3;
		NullCheck(L_31);
		double L_32 = L_31->___x_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_33 = V_5;
		NullCheck(L_33);
		double L_34 = L_33->___x_2;
		V_9 = ((double)(((double)il2cpp_codegen_subtract(L_32, L_34))/(2.0)));
		goto IL_00e2;
	}

IL_00a8:
	{
		// dx = (a.x + c.x) / 2 - bx;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_35 = V_3;
		NullCheck(L_35);
		double L_36 = L_35->___x_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_37 = V_5;
		NullCheck(L_37);
		double L_38 = L_37->___x_2;
		double L_39 = V_6;
		V_8 = ((double)il2cpp_codegen_subtract(((double)(((double)il2cpp_codegen_add(L_36, L_38))/(2.0))), L_39));
		// dy = (a.y + c.y) / 2 - by;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_40 = V_3;
		NullCheck(L_40);
		double L_41 = L_40->___y_3;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_42 = V_5;
		NullCheck(L_42);
		double L_43 = L_42->___y_3;
		double L_44 = V_7;
		V_9 = ((double)il2cpp_codegen_subtract(((double)(((double)il2cpp_codegen_add(L_41, L_43))/(2.0))), L_44));
	}

IL_00e2:
	{
		// a = b;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_45 = V_4;
		V_3 = L_45;
		// b = c;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_46 = V_5;
		V_4 = L_46;
		// h = 1.0;
		V_10 = (1.0);
		// for (int j = 0; j < limit; j++)
		V_13 = 0;
		goto IL_0194;
	}

IL_00fc:
	{
		// test.x = bx + dx * h;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_47 = V_2;
		double L_48 = V_6;
		double L_49 = V_8;
		double L_50 = V_10;
		NullCheck(L_47);
		L_47->___x_2 = ((double)il2cpp_codegen_add(L_48, ((double)il2cpp_codegen_multiply(L_49, L_50))));
		// test.y = by + dy * h;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_51 = V_2;
		double L_52 = V_7;
		double L_53 = V_9;
		double L_54 = V_10;
		NullCheck(L_51);
		L_51->___y_3 = ((double)il2cpp_codegen_add(L_52, ((double)il2cpp_codegen_multiply(L_53, L_54))));
		// if (bounds.Contains(test) && IsPointInPolygon(test, contour) && !IsPointOnSegment(test, contour))
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_55 = V_0;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_56 = V_2;
		NullCheck(L_55);
		bool L_57;
		L_57 = Rectangle_Contains_mE8BE1E8DFEBE3EF1784CFCFB3C93DF2809A87197(L_55, L_56, NULL);
		if (!L_57)
		{
			goto IL_013e;
		}
	}
	{
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_58 = V_2;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_59 = ___0_contour;
		bool L_60;
		L_60 = Contour_IsPointInPolygon_m853A279C7C310A76B85394F9665622BCD0F50430(L_58, L_59, NULL);
		if (!L_60)
		{
			goto IL_013e;
		}
	}
	{
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_61 = V_2;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_62 = ___0_contour;
		bool L_63;
		L_63 = Contour_IsPointOnSegment_m66D26E3455C2BC85A86186BA4D0B629A080A21BE(L_61, L_62, (9.9999999999999998E-13), NULL);
		if (L_63)
		{
			goto IL_013e;
		}
	}
	{
		// return test;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_64 = V_2;
		return L_64;
	}

IL_013e:
	{
		// test.x = bx - dx * h;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_65 = V_2;
		double L_66 = V_6;
		double L_67 = V_8;
		double L_68 = V_10;
		NullCheck(L_65);
		L_65->___x_2 = ((double)il2cpp_codegen_subtract(L_66, ((double)il2cpp_codegen_multiply(L_67, L_68))));
		// test.y = by - dy * h;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_69 = V_2;
		double L_70 = V_7;
		double L_71 = V_9;
		double L_72 = V_10;
		NullCheck(L_69);
		L_69->___y_3 = ((double)il2cpp_codegen_subtract(L_70, ((double)il2cpp_codegen_multiply(L_71, L_72))));
		// if (bounds.Contains(test) && IsPointInPolygon(test, contour) && !IsPointOnSegment(test, contour))
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_73 = V_0;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_74 = V_2;
		NullCheck(L_73);
		bool L_75;
		L_75 = Rectangle_Contains_mE8BE1E8DFEBE3EF1784CFCFB3C93DF2809A87197(L_73, L_74, NULL);
		if (!L_75)
		{
			goto IL_0180;
		}
	}
	{
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_76 = V_2;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_77 = ___0_contour;
		bool L_78;
		L_78 = Contour_IsPointInPolygon_m853A279C7C310A76B85394F9665622BCD0F50430(L_76, L_77, NULL);
		if (!L_78)
		{
			goto IL_0180;
		}
	}
	{
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_79 = V_2;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_80 = ___0_contour;
		bool L_81;
		L_81 = Contour_IsPointOnSegment_m66D26E3455C2BC85A86186BA4D0B629A080A21BE(L_79, L_80, (9.9999999999999998E-13), NULL);
		if (L_81)
		{
			goto IL_0180;
		}
	}
	{
		// return test;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_82 = V_2;
		return L_82;
	}

IL_0180:
	{
		// h = h / 2;
		double L_83 = V_10;
		V_10 = ((double)(L_83/(2.0)));
		// for (int j = 0; j < limit; j++)
		int32_t L_84 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_84, 1));
	}

IL_0194:
	{
		// for (int j = 0; j < limit; j++)
		int32_t L_85 = V_13;
		int32_t L_86 = ___1_limit;
		if ((((int32_t)L_85) < ((int32_t)L_86)))
		{
			goto IL_00fc;
		}
	}
	{
		// for (int i = 0; i < length; i++)
		int32_t L_87 = V_12;
		V_12 = ((int32_t)il2cpp_codegen_add(L_87, 1));
	}

IL_01a2:
	{
		// for (int i = 0; i < length; i++)
		int32_t L_88 = V_12;
		int32_t L_89 = V_1;
		if ((((int32_t)L_88) < ((int32_t)L_89)))
		{
			goto IL_003a;
		}
	}
	{
		// throw new Exception();
		Exception_t* L_90 = (Exception_t*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)));
		NullCheck(L_90);
		Exception__ctor_m203319D1EA1274689B380A947B4ADC8445662B8F(L_90, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_90, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Contour_FindPointInPolygon_m1EA0F170F9981733E20CD3F51393CCE8AE646A90_RuntimeMethod_var)));
	}
}
// System.Boolean TriangleNet.Geometry.Contour::IsPointInPolygon(TriangleNet.Geometry.Point,System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Contour_IsPointInPolygon_m853A279C7C310A76B85394F9665622BCD0F50430 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_point, List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___1_poly, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	double V_1 = 0.0;
	double V_2 = 0.0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	{
		// bool inside = false;
		V_0 = (bool)0;
		// double x = point.x;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_0 = ___0_point;
		NullCheck(L_0);
		double L_1 = L_0->___x_2;
		V_1 = L_1;
		// double y = point.y;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_2 = ___0_point;
		NullCheck(L_2);
		double L_3 = L_2->___y_3;
		V_2 = L_3;
		// int count = poly.Count;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_4 = ___1_poly;
		NullCheck(L_4);
		int32_t L_5;
		L_5 = List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_inline(L_4, List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		V_3 = L_5;
		// for (int i = 0, j = count - 1; i < count; i++)
		V_4 = 0;
		// for (int i = 0, j = count - 1; i < count; i++)
		int32_t L_6 = V_3;
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_6, 1));
		goto IL_00ec;
	}

IL_0024:
	{
		// if (((poly[i].y < y && poly[j].y >= y) || (poly[j].y < y && poly[i].y >= y))
		//     && (poly[i].x <= x || poly[j].x <= x))
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_7 = ___1_poly;
		int32_t L_8 = V_4;
		NullCheck(L_7);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_9;
		L_9 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_7, L_8, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_9);
		double L_10 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_9)->___y_3;
		double L_11 = V_2;
		if ((!(((double)L_10) < ((double)L_11))))
		{
			goto IL_0044;
		}
	}
	{
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_12 = ___1_poly;
		int32_t L_13 = V_5;
		NullCheck(L_12);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_14;
		L_14 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_12, L_13, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_14);
		double L_15 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_14)->___y_3;
		double L_16 = V_2;
		if ((((double)L_15) >= ((double)L_16)))
		{
			goto IL_0067;
		}
	}

IL_0044:
	{
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_17 = ___1_poly;
		int32_t L_18 = V_5;
		NullCheck(L_17);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_19;
		L_19 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_17, L_18, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_19);
		double L_20 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_19)->___y_3;
		double L_21 = V_2;
		if ((!(((double)L_20) < ((double)L_21))))
		{
			goto IL_00e2;
		}
	}
	{
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_22 = ___1_poly;
		int32_t L_23 = V_4;
		NullCheck(L_22);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_24;
		L_24 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_22, L_23, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_24);
		double L_25 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_24)->___y_3;
		double L_26 = V_2;
		if ((!(((double)L_25) >= ((double)L_26))))
		{
			goto IL_00e2;
		}
	}

IL_0067:
	{
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_27 = ___1_poly;
		int32_t L_28 = V_4;
		NullCheck(L_27);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_29;
		L_29 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_27, L_28, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_29);
		double L_30 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_29)->___x_2;
		double L_31 = V_1;
		if ((((double)L_30) <= ((double)L_31)))
		{
			goto IL_0087;
		}
	}
	{
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_32 = ___1_poly;
		int32_t L_33 = V_5;
		NullCheck(L_32);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_34;
		L_34 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_32, L_33, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_34);
		double L_35 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_34)->___x_2;
		double L_36 = V_1;
		if ((!(((double)L_35) <= ((double)L_36))))
		{
			goto IL_00e2;
		}
	}

IL_0087:
	{
		// inside ^= (poly[i].x + (y - poly[i].y) / (poly[j].y - poly[i].y) * (poly[j].x - poly[i].x) < x);
		bool L_37 = V_0;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_38 = ___1_poly;
		int32_t L_39 = V_4;
		NullCheck(L_38);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_40;
		L_40 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_38, L_39, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_40);
		double L_41 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_40)->___x_2;
		double L_42 = V_2;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_43 = ___1_poly;
		int32_t L_44 = V_4;
		NullCheck(L_43);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_45;
		L_45 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_43, L_44, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_45);
		double L_46 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_45)->___y_3;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_47 = ___1_poly;
		int32_t L_48 = V_5;
		NullCheck(L_47);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_49;
		L_49 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_47, L_48, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_49);
		double L_50 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_49)->___y_3;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_51 = ___1_poly;
		int32_t L_52 = V_4;
		NullCheck(L_51);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_53;
		L_53 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_51, L_52, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_53);
		double L_54 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_53)->___y_3;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_55 = ___1_poly;
		int32_t L_56 = V_5;
		NullCheck(L_55);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_57;
		L_57 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_55, L_56, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_57);
		double L_58 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_57)->___x_2;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_59 = ___1_poly;
		int32_t L_60 = V_4;
		NullCheck(L_59);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_61;
		L_61 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_59, L_60, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		NullCheck(L_61);
		double L_62 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_61)->___x_2;
		double L_63 = V_1;
		V_0 = (bool)((int32_t)((int32_t)L_37^((((double)((double)il2cpp_codegen_add(L_41, ((double)il2cpp_codegen_multiply(((double)(((double)il2cpp_codegen_subtract(L_42, L_46))/((double)il2cpp_codegen_subtract(L_50, L_54)))), ((double)il2cpp_codegen_subtract(L_58, L_62))))))) < ((double)L_63))? 1 : 0)));
	}

IL_00e2:
	{
		// j = i;
		int32_t L_64 = V_4;
		V_5 = L_64;
		// for (int i = 0, j = count - 1; i < count; i++)
		int32_t L_65 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_65, 1));
	}

IL_00ec:
	{
		// for (int i = 0, j = count - 1; i < count; i++)
		int32_t L_66 = V_4;
		int32_t L_67 = V_3;
		if ((((int32_t)L_66) < ((int32_t)L_67)))
		{
			goto IL_0024;
		}
	}
	{
		// return inside;
		bool L_68 = V_0;
		return L_68;
	}
}
// System.Boolean TriangleNet.Geometry.Contour::IsPointOnSegment(TriangleNet.Geometry.Point,System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex>,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Contour_IsPointOnSegment_m66D26E3455C2BC85A86186BA4D0B629A080A21BE (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_test, List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___1_contour, double ___2_eps, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		// int count = contour.Count;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_0 = ___1_contour;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_inline(L_0, List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		V_0 = L_1;
		// int i = count - 1;
		int32_t L_2 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		// for (int j = 0; j < count; j++)
		V_2 = 0;
		goto IL_002e;
	}

IL_000f:
	{
		// if (IntersectionHelper.IsPointOnSegment(contour[i], contour[j], test, eps))
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_3 = ___1_contour;
		int32_t L_4 = V_1;
		NullCheck(L_3);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_5;
		L_5 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_3, L_4, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_6 = ___1_contour;
		int32_t L_7 = V_2;
		NullCheck(L_6);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_8;
		L_8 = List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE(L_6, L_7, List_1_get_Item_m4919F7E21A791275FD3546A255BD1CDFD8C343FE_RuntimeMethod_var);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_9 = ___0_test;
		double L_10 = ___2_eps;
		bool L_11;
		L_11 = IntersectionHelper_IsPointOnSegment_m3FEC4A8E81EEE58DCBBFFE1215AB997EBF5B95DC(L_5, L_8, L_9, L_10, NULL);
		if (!L_11)
		{
			goto IL_0028;
		}
	}
	{
		// return true;
		return (bool)1;
	}

IL_0028:
	{
		// i = j;
		int32_t L_12 = V_2;
		V_1 = L_12;
		// for (int j = 0; j < count; j++)
		int32_t L_13 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_002e:
	{
		// for (int j = 0; j < count; j++)
		int32_t L_14 = V_2;
		int32_t L_15 = V_0;
		if ((((int32_t)L_14) < ((int32_t)L_15)))
		{
			goto IL_000f;
		}
	}
	{
		// return false;
		return (bool)0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Int32 TriangleNet.Geometry.Edge::get_P0()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Edge_get_P0_mB84686341C36E484A8875EA8A3836054702B0BFC (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, const RuntimeMethod* method) 
{
	{
		// public int P0 { get; private set; }
		int32_t L_0 = __this->___U3CP0U3Ek__BackingField_0;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Edge::set_P0(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Edge_set_P0_mB0616BBD1AF6210443FF8BF3F3C81F9DDC5728EA (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int P0 { get; private set; }
		int32_t L_0 = ___0_value;
		__this->___U3CP0U3Ek__BackingField_0 = L_0;
		return;
	}
}
// System.Int32 TriangleNet.Geometry.Edge::get_P1()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Edge_get_P1_mBA10A8814DEE82CAE501D7E4A53C683666660312 (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, const RuntimeMethod* method) 
{
	{
		// public int P1 { get; private set; }
		int32_t L_0 = __this->___U3CP1U3Ek__BackingField_1;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Edge::set_P1(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Edge_set_P1_m35B336CD05909FEEE165A4FF77DCDF554D0653E5 (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int P1 { get; private set; }
		int32_t L_0 = ___0_value;
		__this->___U3CP1U3Ek__BackingField_1 = L_0;
		return;
	}
}
// System.Int32 TriangleNet.Geometry.Edge::get_Label()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Edge_get_Label_mDF34FC0C525CBEACF8398156C5B8F35B3F509A27 (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, const RuntimeMethod* method) 
{
	{
		// public int Label { get; private set; }
		int32_t L_0 = __this->___U3CLabelU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Edge::set_Label(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Edge_set_Label_m2CCB72689E3B178FC25C8BDDEC3334E1D3FF101F (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int Label { get; private set; }
		int32_t L_0 = ___0_value;
		__this->___U3CLabelU3Ek__BackingField_2 = L_0;
		return;
	}
}
// System.Void TriangleNet.Geometry.Edge::.ctor(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Edge__ctor_m08AE797534DAB178D0E102E771891AB2E1B3B8CD (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_p0, int32_t ___1_p1, const RuntimeMethod* method) 
{
	{
		// : this(p0, p1, 0)
		int32_t L_0 = ___0_p0;
		int32_t L_1 = ___1_p1;
		Edge__ctor_m357B4ED93E3E0F66F877FADCCB920FE114649073(__this, L_0, L_1, 0, NULL);
		// { }
		return;
	}
}
// System.Void TriangleNet.Geometry.Edge::.ctor(System.Int32,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Edge__ctor_m357B4ED93E3E0F66F877FADCCB920FE114649073 (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_p0, int32_t ___1_p1, int32_t ___2_label, const RuntimeMethod* method) 
{
	{
		// public Edge(int p0, int p1, int label)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// P0 = p0;
		int32_t L_0 = ___0_p0;
		Edge_set_P0_mB0616BBD1AF6210443FF8BF3F3C81F9DDC5728EA_inline(__this, L_0, NULL);
		// P1 = p1;
		int32_t L_1 = ___1_p1;
		Edge_set_P1_m35B336CD05909FEEE165A4FF77DCDF554D0653E5_inline(__this, L_1, NULL);
		// Label = label;
		int32_t L_2 = ___2_label;
		Edge_set_Label_m2CCB72689E3B178FC25C8BDDEC3334E1D3FF101F_inline(__this, L_2, NULL);
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// TriangleNet.Meshing.IMesh TriangleNet.Geometry.ExtensionMethods::Triangulate(TriangleNet.Geometry.IPolygon)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ExtensionMethods_Triangulate_m12D427582993016F2A3C12390CAD2EA958531011 (RuntimeObject* ___0_polygon, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return (new GenericMesher()).Triangulate(polygon, null, null);
		GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD* L_0 = (GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD*)il2cpp_codegen_object_new(GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		GenericMesher__ctor_m77E9F21C2EA55F5B700657945CD08839C46D25D5(L_0, NULL);
		RuntimeObject* L_1 = ___0_polygon;
		NullCheck(L_0);
		RuntimeObject* L_2;
		L_2 = GenericMesher_Triangulate_m3320114AB3BE6550F20D671A006B1F9C4E715E8C(L_0, L_1, (ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC*)NULL, (QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E*)NULL, NULL);
		return L_2;
	}
}
// TriangleNet.Meshing.IMesh TriangleNet.Geometry.ExtensionMethods::Triangulate(TriangleNet.Geometry.IPolygon,TriangleNet.Meshing.ConstraintOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ExtensionMethods_Triangulate_mF222510F2151AFFC4D36F1800D7CC50C9AC7C7F5 (RuntimeObject* ___0_polygon, ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC* ___1_options, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return (new GenericMesher()).Triangulate(polygon, options, null);
		GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD* L_0 = (GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD*)il2cpp_codegen_object_new(GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		GenericMesher__ctor_m77E9F21C2EA55F5B700657945CD08839C46D25D5(L_0, NULL);
		RuntimeObject* L_1 = ___0_polygon;
		ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC* L_2 = ___1_options;
		NullCheck(L_0);
		RuntimeObject* L_3;
		L_3 = GenericMesher_Triangulate_m3320114AB3BE6550F20D671A006B1F9C4E715E8C(L_0, L_1, L_2, (QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E*)NULL, NULL);
		return L_3;
	}
}
// TriangleNet.Meshing.IMesh TriangleNet.Geometry.ExtensionMethods::Triangulate(TriangleNet.Geometry.IPolygon,TriangleNet.Meshing.QualityOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ExtensionMethods_Triangulate_m4F58DC3F6053FB6EADDF00DEDAB6063E469E1D4D (RuntimeObject* ___0_polygon, QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E* ___1_quality, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return (new GenericMesher()).Triangulate(polygon, null, quality);
		GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD* L_0 = (GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD*)il2cpp_codegen_object_new(GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		GenericMesher__ctor_m77E9F21C2EA55F5B700657945CD08839C46D25D5(L_0, NULL);
		RuntimeObject* L_1 = ___0_polygon;
		QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E* L_2 = ___1_quality;
		NullCheck(L_0);
		RuntimeObject* L_3;
		L_3 = GenericMesher_Triangulate_m3320114AB3BE6550F20D671A006B1F9C4E715E8C(L_0, L_1, (ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC*)NULL, L_2, NULL);
		return L_3;
	}
}
// TriangleNet.Meshing.IMesh TriangleNet.Geometry.ExtensionMethods::Triangulate(TriangleNet.Geometry.IPolygon,TriangleNet.Meshing.ConstraintOptions,TriangleNet.Meshing.QualityOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ExtensionMethods_Triangulate_mCB4143823FF4762006D2DC1FF2460FDBD37799EE (RuntimeObject* ___0_polygon, ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC* ___1_options, QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E* ___2_quality, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return (new GenericMesher()).Triangulate(polygon, options, quality);
		GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD* L_0 = (GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD*)il2cpp_codegen_object_new(GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		GenericMesher__ctor_m77E9F21C2EA55F5B700657945CD08839C46D25D5(L_0, NULL);
		RuntimeObject* L_1 = ___0_polygon;
		ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC* L_2 = ___1_options;
		QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E* L_3 = ___2_quality;
		NullCheck(L_0);
		RuntimeObject* L_4;
		L_4 = GenericMesher_Triangulate_m3320114AB3BE6550F20D671A006B1F9C4E715E8C(L_0, L_1, L_2, L_3, NULL);
		return L_4;
	}
}
// TriangleNet.Meshing.IMesh TriangleNet.Geometry.ExtensionMethods::Triangulate(TriangleNet.Geometry.IPolygon,TriangleNet.Meshing.ConstraintOptions,TriangleNet.Meshing.QualityOptions,TriangleNet.Meshing.ITriangulator)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ExtensionMethods_Triangulate_m0D4019651201797690178EE12B935E38E76D5067 (RuntimeObject* ___0_polygon, ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC* ___1_options, QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E* ___2_quality, RuntimeObject* ___3_triangulator, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return (new GenericMesher(triangulator)).Triangulate(polygon, options, quality);
		RuntimeObject* L_0 = ___3_triangulator;
		GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD* L_1 = (GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD*)il2cpp_codegen_object_new(GenericMesher_t0C318FCB2FD211E89575E3CDFB1869FE7B9C7DBD_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		GenericMesher__ctor_mC1CE60AA43F1A3BC515E5B4BAE56B54701842B3F(L_1, L_0, NULL);
		RuntimeObject* L_2 = ___0_polygon;
		ConstraintOptions_tF3B11E3DC71C05E53C04A2CBF27C4BBFC43416BC* L_3 = ___1_options;
		QualityOptions_t7C88D57BB63217EE7B1747BF60401993A173631E* L_4 = ___2_quality;
		NullCheck(L_1);
		RuntimeObject* L_5;
		L_5 = GenericMesher_Triangulate_m3320114AB3BE6550F20D671A006B1F9C4E715E8C(L_1, L_2, L_3, L_4, NULL);
		return L_5;
	}
}
// System.Boolean TriangleNet.Geometry.ExtensionMethods::Contains(TriangleNet.Geometry.ITriangle,TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ExtensionMethods_Contains_mB3692FB0A33E9A00F59187E1E27BCE600778883F (RuntimeObject* ___0_triangle, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___1_p, const RuntimeMethod* method) 
{
	{
		// return Contains(triangle, p.X, p.Y);
		RuntimeObject* L_0 = ___0_triangle;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_1 = ___1_p;
		NullCheck(L_1);
		double L_2;
		L_2 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_1, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_3 = ___1_p;
		NullCheck(L_3);
		double L_4;
		L_4 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_3, NULL);
		bool L_5;
		L_5 = ExtensionMethods_Contains_m2DA8B67B73946251BF8263413FCE93A0AC2D70FA(L_0, L_2, L_4, NULL);
		return L_5;
	}
}
// System.Boolean TriangleNet.Geometry.ExtensionMethods::Contains(TriangleNet.Geometry.ITriangle,System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ExtensionMethods_Contains_m2DA8B67B73946251BF8263413FCE93A0AC2D70FA (RuntimeObject* ___0_triangle, double ___1_x, double ___2_y, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITriangle_t7B68E84B00E0B87B508BA815EB6B4AE1D960CD99_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* V_0 = NULL;
	Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* V_1 = NULL;
	Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* V_2 = NULL;
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_3 = NULL;
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_4 = NULL;
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_5 = NULL;
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_6 = NULL;
	double V_7 = 0.0;
	double V_8 = 0.0;
	{
		// var t0 = triangle.GetVertex(0);
		RuntimeObject* L_0 = ___0_triangle;
		NullCheck(L_0);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_1;
		L_1 = InterfaceFuncInvoker1< Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A*, int32_t >::Invoke(6 /* TriangleNet.Geometry.Vertex TriangleNet.Geometry.ITriangle::GetVertex(System.Int32) */, ITriangle_t7B68E84B00E0B87B508BA815EB6B4AE1D960CD99_il2cpp_TypeInfo_var, L_0, 0);
		V_0 = L_1;
		// var t1 = triangle.GetVertex(1);
		RuntimeObject* L_2 = ___0_triangle;
		NullCheck(L_2);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_3;
		L_3 = InterfaceFuncInvoker1< Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A*, int32_t >::Invoke(6 /* TriangleNet.Geometry.Vertex TriangleNet.Geometry.ITriangle::GetVertex(System.Int32) */, ITriangle_t7B68E84B00E0B87B508BA815EB6B4AE1D960CD99_il2cpp_TypeInfo_var, L_2, 1);
		V_1 = L_3;
		// var t2 = triangle.GetVertex(2);
		RuntimeObject* L_4 = ___0_triangle;
		NullCheck(L_4);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_5;
		L_5 = InterfaceFuncInvoker1< Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A*, int32_t >::Invoke(6 /* TriangleNet.Geometry.Vertex TriangleNet.Geometry.ITriangle::GetVertex(System.Int32) */, ITriangle_t7B68E84B00E0B87B508BA815EB6B4AE1D960CD99_il2cpp_TypeInfo_var, L_4, 2);
		V_2 = L_5;
		// Point d0 = new Point(t1.X - t0.X, t1.Y - t0.Y);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_6 = V_1;
		NullCheck(L_6);
		double L_7;
		L_7 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_6, NULL);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_8 = V_0;
		NullCheck(L_8);
		double L_9;
		L_9 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_8, NULL);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_10 = V_1;
		NullCheck(L_10);
		double L_11;
		L_11 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_10, NULL);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_12 = V_0;
		NullCheck(L_12);
		double L_13;
		L_13 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_12, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_14 = (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)il2cpp_codegen_object_new(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		NullCheck(L_14);
		Point__ctor_m36BE66184AB548B99409ADDD4178D0019D4E0289(L_14, ((double)il2cpp_codegen_subtract(L_7, L_9)), ((double)il2cpp_codegen_subtract(L_11, L_13)), NULL);
		V_3 = L_14;
		// Point d1 = new Point(t2.X - t0.X, t2.Y - t0.Y);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_15 = V_2;
		NullCheck(L_15);
		double L_16;
		L_16 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_15, NULL);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_17 = V_0;
		NullCheck(L_17);
		double L_18;
		L_18 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_17, NULL);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_19 = V_2;
		NullCheck(L_19);
		double L_20;
		L_20 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_19, NULL);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_21 = V_0;
		NullCheck(L_21);
		double L_22;
		L_22 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_21, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_23 = (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)il2cpp_codegen_object_new(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		NullCheck(L_23);
		Point__ctor_m36BE66184AB548B99409ADDD4178D0019D4E0289(L_23, ((double)il2cpp_codegen_subtract(L_16, L_18)), ((double)il2cpp_codegen_subtract(L_20, L_22)), NULL);
		V_4 = L_23;
		// Point d2 = new Point(x - t0.X, y - t0.Y);
		double L_24 = ___1_x;
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_25 = V_0;
		NullCheck(L_25);
		double L_26;
		L_26 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_25, NULL);
		double L_27 = ___2_y;
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_28 = V_0;
		NullCheck(L_28);
		double L_29;
		L_29 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_28, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_30 = (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)il2cpp_codegen_object_new(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		NullCheck(L_30);
		Point__ctor_m36BE66184AB548B99409ADDD4178D0019D4E0289(L_30, ((double)il2cpp_codegen_subtract(L_24, L_26)), ((double)il2cpp_codegen_subtract(L_27, L_29)), NULL);
		// Point c0 = new Point(-d0.Y, d0.X);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_31 = V_3;
		NullCheck(L_31);
		double L_32;
		L_32 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_31, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_33 = V_3;
		NullCheck(L_33);
		double L_34;
		L_34 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_33, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_35 = (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)il2cpp_codegen_object_new(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		NullCheck(L_35);
		Point__ctor_m36BE66184AB548B99409ADDD4178D0019D4E0289(L_35, ((-L_32)), L_34, NULL);
		V_5 = L_35;
		// Point c1 = new Point(-d1.Y, d1.X);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_36 = V_4;
		NullCheck(L_36);
		double L_37;
		L_37 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_36, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_38 = V_4;
		NullCheck(L_38);
		double L_39;
		L_39 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_38, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_40 = (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)il2cpp_codegen_object_new(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		NullCheck(L_40);
		Point__ctor_m36BE66184AB548B99409ADDD4178D0019D4E0289(L_40, ((-L_37)), L_39, NULL);
		V_6 = L_40;
		// double s = DotProduct(d2, c1) / DotProduct(d0, c1);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_41 = L_30;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_42 = V_6;
		double L_43;
		L_43 = ExtensionMethods_DotProduct_m4462CDC92CEC0443C86DAD5484D3E9FAAE2DB58B(L_41, L_42, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_44 = V_3;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_45 = V_6;
		double L_46;
		L_46 = ExtensionMethods_DotProduct_m4462CDC92CEC0443C86DAD5484D3E9FAAE2DB58B(L_44, L_45, NULL);
		V_7 = ((double)(L_43/L_46));
		// double v = DotProduct(d2, c0) / DotProduct(d1, c0);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_47 = V_5;
		double L_48;
		L_48 = ExtensionMethods_DotProduct_m4462CDC92CEC0443C86DAD5484D3E9FAAE2DB58B(L_41, L_47, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_49 = V_4;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_50 = V_5;
		double L_51;
		L_51 = ExtensionMethods_DotProduct_m4462CDC92CEC0443C86DAD5484D3E9FAAE2DB58B(L_49, L_50, NULL);
		V_8 = ((double)(L_48/L_51));
		// if (s >= 0 && v >= 0 && ((s + v) <= 1))
		double L_52 = V_7;
		if ((!(((double)L_52) >= ((double)(0.0)))))
		{
			goto IL_00ea;
		}
	}
	{
		double L_53 = V_8;
		if ((!(((double)L_53) >= ((double)(0.0)))))
		{
			goto IL_00ea;
		}
	}
	{
		double L_54 = V_7;
		double L_55 = V_8;
		if ((!(((double)((double)il2cpp_codegen_add(L_54, L_55))) <= ((double)(1.0)))))
		{
			goto IL_00ea;
		}
	}
	{
		// return true;
		return (bool)1;
	}

IL_00ea:
	{
		// return false;
		return (bool)0;
	}
}
// TriangleNet.Geometry.Rectangle TriangleNet.Geometry.ExtensionMethods::Bounds(TriangleNet.Geometry.ITriangle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* ExtensionMethods_Bounds_mA8A3F7933A6663B44592ED53E10432FA5048FB64 (RuntimeObject* ___0_triangle, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ITriangle_t7B68E84B00E0B87B508BA815EB6B4AE1D960CD99_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* V_0 = NULL;
	int32_t V_1 = 0;
	{
		// var bounds = new Rectangle();
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_0 = (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B*)il2cpp_codegen_object_new(Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Rectangle__ctor_m826E64394C092D2A9D743261E2A10E22F9697FD6(L_0, NULL);
		V_0 = L_0;
		// for (int i = 0; i < 3; i++)
		V_1 = 0;
		goto IL_001b;
	}

IL_000a:
	{
		// bounds.Expand(triangle.GetVertex(i));
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_1 = V_0;
		RuntimeObject* L_2 = ___0_triangle;
		int32_t L_3 = V_1;
		NullCheck(L_2);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_4;
		L_4 = InterfaceFuncInvoker1< Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A*, int32_t >::Invoke(6 /* TriangleNet.Geometry.Vertex TriangleNet.Geometry.ITriangle::GetVertex(System.Int32) */, ITriangle_t7B68E84B00E0B87B508BA815EB6B4AE1D960CD99_il2cpp_TypeInfo_var, L_2, L_3);
		NullCheck(L_1);
		Rectangle_Expand_mB0DC57451EAFE5F38DAAB3C29CBD577977A4200B(L_1, L_4, NULL);
		// for (int i = 0; i < 3; i++)
		int32_t L_5 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_001b:
	{
		// for (int i = 0; i < 3; i++)
		int32_t L_6 = V_1;
		if ((((int32_t)L_6) < ((int32_t)3)))
		{
			goto IL_000a;
		}
	}
	{
		// return bounds;
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_7 = V_0;
		return L_7;
	}
}
// System.Double TriangleNet.Geometry.ExtensionMethods::DotProduct(TriangleNet.Geometry.Point,TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double ExtensionMethods_DotProduct_m4462CDC92CEC0443C86DAD5484D3E9FAAE2DB58B (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_p, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___1_q, const RuntimeMethod* method) 
{
	{
		// return p.X * q.X + p.Y * q.Y;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_0 = ___0_p;
		NullCheck(L_0);
		double L_1;
		L_1 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_0, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_2 = ___1_q;
		NullCheck(L_2);
		double L_3;
		L_3 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_2, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_4 = ___0_p;
		NullCheck(L_4);
		double L_5;
		L_5 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_4, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_6 = ___1_q;
		NullCheck(L_6);
		double L_7;
		L_7 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_6, NULL);
		return ((double)il2cpp_codegen_add(((double)il2cpp_codegen_multiply(L_1, L_3)), ((double)il2cpp_codegen_multiply(L_5, L_7))));
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void TriangleNet.Geometry.Point::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Point__ctor_m4B0499A60884D4097A6297F5755770AC1A7378BF (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) 
{
	{
		// : this(0.0, 0.0, 0)
		Point__ctor_m6F9D396D184EC6C20BF40C449AB7964256A0C863(__this, (0.0), (0.0), 0, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Point::.ctor(System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Point__ctor_m36BE66184AB548B99409ADDD4178D0019D4E0289 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, double ___0_x, double ___1_y, const RuntimeMethod* method) 
{
	{
		// : this(x, y, 0)
		double L_0 = ___0_x;
		double L_1 = ___1_y;
		Point__ctor_m6F9D396D184EC6C20BF40C449AB7964256A0C863(__this, L_0, L_1, 0, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Point::.ctor(System.Double,System.Double,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Point__ctor_m6F9D396D184EC6C20BF40C449AB7964256A0C863 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, double ___0_x, double ___1_y, int32_t ___2_label, const RuntimeMethod* method) 
{
	{
		// public Point(double x, double y, int label)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// this.x = x;
		double L_0 = ___0_x;
		__this->___x_2 = L_0;
		// this.y = y;
		double L_1 = ___1_y;
		__this->___y_3 = L_1;
		// this.label = label;
		int32_t L_2 = ___2_label;
		__this->___label_1 = L_2;
		// }
		return;
	}
}
// System.Int32 TriangleNet.Geometry.Point::get_ID()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Point_get_ID_mA48151968F888DBAECE256D5F638C232DCDF49FA (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) 
{
	{
		// get { return id; }
		int32_t L_0 = __this->___id_0;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Point::set_ID(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Point_set_ID_m3BC89138A11032784CFC02629757DFC86EB42D73 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// set { id = value; }
		int32_t L_0 = ___0_value;
		__this->___id_0 = L_0;
		// set { id = value; }
		return;
	}
}
// System.Double TriangleNet.Geometry.Point::get_X()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) 
{
	{
		// get { return x; }
		double L_0 = __this->___x_2;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Point::set_X(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Point_set_X_mA5B40A9973CD8AD464D727AD3F24F03F545262CD (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, double ___0_value, const RuntimeMethod* method) 
{
	{
		// set { x = value; }
		double L_0 = ___0_value;
		__this->___x_2 = L_0;
		// set { x = value; }
		return;
	}
}
// System.Double TriangleNet.Geometry.Point::get_Y()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) 
{
	{
		// get { return y; }
		double L_0 = __this->___y_3;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Point::set_Y(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Point_set_Y_m1B6627F1468A690C6B5AA710D8936DC59885A3B4 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, double ___0_value, const RuntimeMethod* method) 
{
	{
		// set { y = value; }
		double L_0 = ___0_value;
		__this->___y_3 = L_0;
		// set { y = value; }
		return;
	}
}
// System.Int32 TriangleNet.Geometry.Point::get_Label()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Point_get_Label_mF91C777345143349260ED3914CA7F4553840EA50 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) 
{
	{
		// get { return label; }
		int32_t L_0 = __this->___label_1;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Point::set_Label(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Point_set_Label_m56BE8BDDEF3E49D128C39E563A72241E3FDA21D5 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// set { label = value; }
		int32_t L_0 = ___0_value;
		__this->___label_1 = L_0;
		// set { label = value; }
		return;
	}
}
// System.Boolean TriangleNet.Geometry.Point::op_Equality(TriangleNet.Geometry.Point,TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Point_op_Equality_m130AAFCC6C0C4CD8FD648741E55C3B7806E4AD0F (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_a, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___1_b, const RuntimeMethod* method) 
{
	{
		// if (a is null)
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_0 = ___0_a;
		if (L_0)
		{
			goto IL_0008;
		}
	}
	{
		// return b is null;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_1 = ___1_b;
		return (bool)((((RuntimeObject*)(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_1) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
	}

IL_0008:
	{
		// if (ReferenceEquals(a, b))
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_2 = ___0_a;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_3 = ___1_b;
		if ((!(((RuntimeObject*)(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_2) == ((RuntimeObject*)(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_3))))
		{
			goto IL_000e;
		}
	}
	{
		// return true;
		return (bool)1;
	}

IL_000e:
	{
		// return a.Equals(b);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_4 = ___0_a;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_5 = ___1_b;
		NullCheck(L_4);
		bool L_6;
		L_6 = Point_Equals_mBC8DC476D701493987584DCC813F8CEA1E68C59E(L_4, L_5, NULL);
		return L_6;
	}
}
// System.Boolean TriangleNet.Geometry.Point::op_Inequality(TriangleNet.Geometry.Point,TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Point_op_Inequality_m4D8361F551BF391D4383DDDE30A9D81A9E73B387 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_a, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___1_b, const RuntimeMethod* method) 
{
	{
		// return !(a == b);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_0 = ___0_a;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_1 = ___1_b;
		bool L_2;
		L_2 = Point_op_Equality_m130AAFCC6C0C4CD8FD648741E55C3B7806E4AD0F(L_0, L_1, NULL);
		return (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}
}
// System.Boolean TriangleNet.Geometry.Point::Equals(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Point_Equals_m91F43645103F12E853927759320BBD77F52363A0 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public override bool Equals(object obj) => Equals(obj as Point);
		RuntimeObject* L_0 = ___0_obj;
		bool L_1;
		L_1 = Point_Equals_mBC8DC476D701493987584DCC813F8CEA1E68C59E(__this, ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)IsInstClass((RuntimeObject*)L_0, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var)), NULL);
		return L_1;
	}
}
// System.Boolean TriangleNet.Geometry.Point::Equals(TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Point_Equals_mBC8DC476D701493987584DCC813F8CEA1E68C59E (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_p, const RuntimeMethod* method) 
{
	{
		// if (p is null)
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_0 = ___0_p;
		if (L_0)
		{
			goto IL_0005;
		}
	}
	{
		// return false;
		return (bool)0;
	}

IL_0005:
	{
		// return (x == p.x) && (y == p.y);
		double L_1 = __this->___x_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_2 = ___0_p;
		NullCheck(L_2);
		double L_3 = L_2->___x_2;
		if ((!(((double)L_1) == ((double)L_3))))
		{
			goto IL_0022;
		}
	}
	{
		double L_4 = __this->___y_3;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_5 = ___0_p;
		NullCheck(L_5);
		double L_6 = L_5->___y_3;
		return (bool)((((double)L_4) == ((double)L_6))? 1 : 0);
	}

IL_0022:
	{
		return (bool)0;
	}
}
// System.Int32 TriangleNet.Geometry.Point::CompareTo(TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Point_CompareTo_mDC1E287A3A67518DC43924A516F6E1BFC88BCBA8 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_other, const RuntimeMethod* method) 
{
	{
		// if (x == other.x && y == other.y)
		double L_0 = __this->___x_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_1 = ___0_other;
		NullCheck(L_1);
		double L_2 = L_1->___x_2;
		if ((!(((double)L_0) == ((double)L_2))))
		{
			goto IL_001e;
		}
	}
	{
		double L_3 = __this->___y_3;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_4 = ___0_other;
		NullCheck(L_4);
		double L_5 = L_4->___y_3;
		if ((!(((double)L_3) == ((double)L_5))))
		{
			goto IL_001e;
		}
	}
	{
		// return 0;
		return 0;
	}

IL_001e:
	{
		// return (x < other.x || (x == other.x && y < other.y)) ? -1 : 1;
		double L_6 = __this->___x_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_7 = ___0_other;
		NullCheck(L_7);
		double L_8 = L_7->___x_2;
		if ((((double)L_6) < ((double)L_8)))
		{
			goto IL_004a;
		}
	}
	{
		double L_9 = __this->___x_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_10 = ___0_other;
		NullCheck(L_10);
		double L_11 = L_10->___x_2;
		if ((!(((double)L_9) == ((double)L_11))))
		{
			goto IL_0048;
		}
	}
	{
		double L_12 = __this->___y_3;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_13 = ___0_other;
		NullCheck(L_13);
		double L_14 = L_13->___y_3;
		if ((((double)L_12) < ((double)L_14)))
		{
			goto IL_004a;
		}
	}

IL_0048:
	{
		return 1;
	}

IL_004a:
	{
		return (-1);
	}
}
// System.Int32 TriangleNet.Geometry.Point::GetHashCode()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Point_GetHashCode_m1EA114661D1F9D9684A44407C3E3C7C2B0C396B1 (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) 
{
	{
		// int hash = 19;
		// hash = hash * 31 + x.GetHashCode();
		double* L_0 = (double*)(&__this->___x_2);
		int32_t L_1;
		L_1 = Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline(L_0, NULL);
		// hash = hash * 31 + y.GetHashCode();
		double* L_2 = (double*)(&__this->___y_3);
		int32_t L_3;
		L_3 = Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline(L_2, NULL);
		// return hash;
		return ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_multiply(((int32_t)19), ((int32_t)31))), L_1)), ((int32_t)31))), L_3));
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Collections.Generic.List`1<TriangleNet.Geometry.Vertex> TriangleNet.Geometry.Polygon::get_Points()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* Polygon_get_Points_m977770F70E234D61169885A4A144DB3DA145803C (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) 
{
	{
		// public List<Vertex> Points => points;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_0 = __this->___points_0;
		return L_0;
	}
}
// System.Collections.Generic.List`1<TriangleNet.Geometry.Point> TriangleNet.Geometry.Polygon::get_Holes()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE* Polygon_get_Holes_mEF6CD71F2BF46E48C82B849D2D2439CC0EE306E6 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) 
{
	{
		// public List<Point> Holes => holes;
		List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE* L_0 = __this->___holes_2;
		return L_0;
	}
}
// System.Collections.Generic.List`1<TriangleNet.Geometry.RegionPointer> TriangleNet.Geometry.Polygon::get_Regions()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tC9803D99D64F5D893C71690F4B65415B86B42629* Polygon_get_Regions_m660FF6A0859225FB2AAC663ED02B6679B866CC43 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) 
{
	{
		// public List<RegionPointer> Regions => regions;
		List_1_tC9803D99D64F5D893C71690F4B65415B86B42629* L_0 = __this->___regions_3;
		return L_0;
	}
}
// System.Collections.Generic.List`1<TriangleNet.Geometry.ISegment> TriangleNet.Geometry.Polygon::get_Segments()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* Polygon_get_Segments_mC8000C2565E23F836C04AC3239B8A6F7783B211C (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) 
{
	{
		// public List<ISegment> Segments => segments;
		List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* L_0 = __this->___segments_1;
		return L_0;
	}
}
// System.Boolean TriangleNet.Geometry.Polygon::get_HasPointMarkers()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Polygon_get_HasPointMarkers_m3CC713DE893636DE0799ECB0804B628795E1E505 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) 
{
	{
		// public bool HasPointMarkers { get; set; }
		bool L_0 = __this->___U3CHasPointMarkersU3Ek__BackingField_4;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Polygon::set_HasPointMarkers(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_set_HasPointMarkers_m18685DE71EEBCC7E72D83FBDF5B812610C25E51A (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// public bool HasPointMarkers { get; set; }
		bool L_0 = ___0_value;
		__this->___U3CHasPointMarkersU3Ek__BackingField_4 = L_0;
		return;
	}
}
// System.Boolean TriangleNet.Geometry.Polygon::get_HasSegmentMarkers()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Polygon_get_HasSegmentMarkers_m8FF22D23BBB46441B24C62264B0C2285858DF6E4 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) 
{
	{
		// public bool HasSegmentMarkers { get; set; }
		bool L_0 = __this->___U3CHasSegmentMarkersU3Ek__BackingField_5;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Polygon::set_HasSegmentMarkers(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_set_HasSegmentMarkers_mCCFDDD29B78E8945420060057599DA63DB064B38 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// public bool HasSegmentMarkers { get; set; }
		bool L_0 = ___0_value;
		__this->___U3CHasSegmentMarkersU3Ek__BackingField_5 = L_0;
		return;
	}
}
// System.Int32 TriangleNet.Geometry.Polygon::get_Count()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Polygon_get_Count_m6FADF2897F9C0F0BEFB31C74F0DB8C6DB322555A (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// get { return points.Count; }
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_0 = __this->___points_0;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_inline(L_0, List_1_get_Count_m37957EFA4DE3BB6FD2D94B123B8FB3507779CF7A_RuntimeMethod_var);
		return L_1;
	}
}
// System.Void TriangleNet.Geometry.Polygon::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon__ctor_mE077CFCA7D8FE4920B4106B175A66AF2C898427B (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) 
{
	{
		// : this(3, false)
		Polygon__ctor_mE632B4B8B90E7934A628A8D2459122EB1F00BF89(__this, 3, (bool)0, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Polygon::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon__ctor_m2B02A0E13D206DAF8453C809338460A2DF0F9BE2 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		// : this(capacity, false)
		int32_t L_0 = ___0_capacity;
		Polygon__ctor_mE632B4B8B90E7934A628A8D2459122EB1F00BF89(__this, L_0, (bool)0, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Polygon::.ctor(System.Int32,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon__ctor_mE632B4B8B90E7934A628A8D2459122EB1F00BF89 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, int32_t ___0_capacity, bool ___1_markers, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m0F779156FD1338918FE0F75C38BB5F125B2481FD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m727631CEA562FE331684A8FEB77B31AAAFF8EA5F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mB6A622E23FCC654DEFEF1E7782145EC90D05592C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mE9B028637F05103882B499E0D71BB1C14F2F5382_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tC9803D99D64F5D893C71690F4B65415B86B42629_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public Polygon(int capacity, bool markers)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// points = new List<Vertex>(capacity);
		int32_t L_0 = ___0_capacity;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_1 = (List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C*)il2cpp_codegen_object_new(List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		List_1__ctor_mE9B028637F05103882B499E0D71BB1C14F2F5382(L_1, L_0, List_1__ctor_mE9B028637F05103882B499E0D71BB1C14F2F5382_RuntimeMethod_var);
		__this->___points_0 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___points_0), (void*)L_1);
		// holes = new List<Point>();
		List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE* L_2 = (List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE*)il2cpp_codegen_object_new(List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		List_1__ctor_m727631CEA562FE331684A8FEB77B31AAAFF8EA5F(L_2, List_1__ctor_m727631CEA562FE331684A8FEB77B31AAAFF8EA5F_RuntimeMethod_var);
		__this->___holes_2 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___holes_2), (void*)L_2);
		// regions = new List<RegionPointer>();
		List_1_tC9803D99D64F5D893C71690F4B65415B86B42629* L_3 = (List_1_tC9803D99D64F5D893C71690F4B65415B86B42629*)il2cpp_codegen_object_new(List_1_tC9803D99D64F5D893C71690F4B65415B86B42629_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		List_1__ctor_m0F779156FD1338918FE0F75C38BB5F125B2481FD(L_3, List_1__ctor_m0F779156FD1338918FE0F75C38BB5F125B2481FD_RuntimeMethod_var);
		__this->___regions_3 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___regions_3), (void*)L_3);
		// segments = new List<ISegment>();
		List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* L_4 = (List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431*)il2cpp_codegen_object_new(List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431_il2cpp_TypeInfo_var);
		NullCheck(L_4);
		List_1__ctor_mB6A622E23FCC654DEFEF1E7782145EC90D05592C(L_4, List_1__ctor_mB6A622E23FCC654DEFEF1E7782145EC90D05592C_RuntimeMethod_var);
		__this->___segments_1 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___segments_1), (void*)L_4);
		// HasPointMarkers = markers;
		bool L_5 = ___1_markers;
		Polygon_set_HasPointMarkers_m18685DE71EEBCC7E72D83FBDF5B812610C25E51A_inline(__this, L_5, NULL);
		// HasSegmentMarkers = markers;
		bool L_6 = ___1_markers;
		Polygon_set_HasSegmentMarkers_mCCFDDD29B78E8945420060057599DA63DB064B38_inline(__this, L_6, NULL);
		// }
		return;
	}
}
// TriangleNet.Geometry.Rectangle TriangleNet.Geometry.Polygon::Bounds()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* Polygon_Bounds_mDB1C0C512A809BB2C867CFA00142BE9DF37701F5 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// var bounds = new Rectangle();
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_0 = (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B*)il2cpp_codegen_object_new(Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Rectangle__ctor_m826E64394C092D2A9D743261E2A10E22F9697FD6(L_0, NULL);
		// bounds.Expand(points);
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_1 = L_0;
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_2 = __this->___points_0;
		NullCheck(L_1);
		Rectangle_Expand_m866BD091569A256E1E06FC3E6B3627DFC125FDD7(L_1, L_2, NULL);
		// return bounds;
		return L_1;
	}
}
// System.Void TriangleNet.Geometry.Polygon::Add(TriangleNet.Geometry.Vertex)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_Add_m9C17F8D8192E93135EDECCD3D95A5F21D31AFD90 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* ___0_vertex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// points.Add(vertex);
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_0 = __this->___points_0;
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_1 = ___0_vertex;
		NullCheck(L_0);
		List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_inline(L_0, L_1, List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Polygon::Add(TriangleNet.Geometry.ISegment,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_Add_m0A8A0AD4B84341199671D9865554CB5C409D19E3 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, RuntimeObject* ___0_segment, bool ___1_insert, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ISegment_t7C45A404D940E12DAB92D9973B6FA4B09F523949_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// segments.Add(segment);
		List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* L_0 = __this->___segments_1;
		RuntimeObject* L_1 = ___0_segment;
		NullCheck(L_0);
		List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_inline(L_0, L_1, List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_RuntimeMethod_var);
		// if (insert)
		bool L_2 = ___1_insert;
		if (!L_2)
		{
			goto IL_0033;
		}
	}
	{
		// points.Add(segment.GetVertex(0));
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_3 = __this->___points_0;
		RuntimeObject* L_4 = ___0_segment;
		NullCheck(L_4);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_5;
		L_5 = InterfaceFuncInvoker1< Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A*, int32_t >::Invoke(0 /* TriangleNet.Geometry.Vertex TriangleNet.Geometry.ISegment::GetVertex(System.Int32) */, ISegment_t7C45A404D940E12DAB92D9973B6FA4B09F523949_il2cpp_TypeInfo_var, L_4, 0);
		NullCheck(L_3);
		List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_inline(L_3, L_5, List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_RuntimeMethod_var);
		// points.Add(segment.GetVertex(1));
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_6 = __this->___points_0;
		RuntimeObject* L_7 = ___0_segment;
		NullCheck(L_7);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_8;
		L_8 = InterfaceFuncInvoker1< Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A*, int32_t >::Invoke(0 /* TriangleNet.Geometry.Vertex TriangleNet.Geometry.ISegment::GetVertex(System.Int32) */, ISegment_t7C45A404D940E12DAB92D9973B6FA4B09F523949_il2cpp_TypeInfo_var, L_7, 1);
		NullCheck(L_6);
		List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_inline(L_6, L_8, List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_RuntimeMethod_var);
	}

IL_0033:
	{
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Polygon::Add(TriangleNet.Geometry.ISegment,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_Add_mCC5B8ACD889C5BD7244D8085A07954EAD88DEDB8 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, RuntimeObject* ___0_segment, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ISegment_t7C45A404D940E12DAB92D9973B6FA4B09F523949_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// segments.Add(segment);
		List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* L_0 = __this->___segments_1;
		RuntimeObject* L_1 = ___0_segment;
		NullCheck(L_0);
		List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_inline(L_0, L_1, List_1_Add_m34181441E27A424DDDFCF87E8DBBDDA81B9BA08A_RuntimeMethod_var);
		// points.Add(segment.GetVertex(index));
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_2 = __this->___points_0;
		RuntimeObject* L_3 = ___0_segment;
		int32_t L_4 = ___1_index;
		NullCheck(L_3);
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_5;
		L_5 = InterfaceFuncInvoker1< Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A*, int32_t >::Invoke(0 /* TriangleNet.Geometry.Vertex TriangleNet.Geometry.ISegment::GetVertex(System.Int32) */, ISegment_t7C45A404D940E12DAB92D9973B6FA4B09F523949_il2cpp_TypeInfo_var, L_3, L_4);
		NullCheck(L_2);
		List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_inline(L_2, L_5, List_1_Add_mB0500A32867277C1AF7B9683C3D3DFF025A84661_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Polygon::AddContourPointsAndSegments(TriangleNet.Geometry.Contour)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_AddContourPointsAndSegments_m1C3789D2CF4448291C1335664C7B2BE9E11DCA8B (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* ___0_contour, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_AddRange_m36112548B1DAAA54724D07790D3870E097280A93_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_AddRange_mE6E8EB92058F5D3CE0D7C8F8F704530F831AB73F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// points.AddRange(contour.Points);
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_0 = __this->___points_0;
		Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* L_1 = ___0_contour;
		NullCheck(L_1);
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_2;
		L_2 = Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07_inline(L_1, NULL);
		NullCheck(L_0);
		List_1_AddRange_mE6E8EB92058F5D3CE0D7C8F8F704530F831AB73F(L_0, L_2, List_1_AddRange_mE6E8EB92058F5D3CE0D7C8F8F704530F831AB73F_RuntimeMethod_var);
		// segments.AddRange(contour.GetSegments());
		List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* L_3 = __this->___segments_1;
		Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* L_4 = ___0_contour;
		NullCheck(L_4);
		List_1_tF687B6ABA794A0BF149886EB0A6359AC1BAE1431* L_5;
		L_5 = Contour_GetSegments_m64CB26CBBFADDF36C3DF408568481DCAA624DDEF(L_4, NULL);
		NullCheck(L_3);
		List_1_AddRange_m36112548B1DAAA54724D07790D3870E097280A93(L_3, L_5, List_1_AddRange_m36112548B1DAAA54724D07790D3870E097280A93_RuntimeMethod_var);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Polygon::Add(TriangleNet.Geometry.Contour,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_Add_m84555856F518C114A74BEC1359BA35EA73492AC1 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* ___0_contour, int32_t ___1_regionlabel, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mDF33EBADE6B533124F05BADC13B657B09BA0A931_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_0 = NULL;
	{
		// if (regionlabel != 0)
		int32_t L_0 = ___1_regionlabel;
		if (!L_0)
		{
			goto IL_0031;
		}
	}
	{
		// var interiorPoint = contour.FindInteriorPoint();
		Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* L_1 = ___0_contour;
		NullCheck(L_1);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_2;
		L_2 = Contour_FindInteriorPoint_m405B8515C17A404A24B40398F1390C050BE380B1(L_1, 5, (2.0000000000000002E-05), NULL);
		V_0 = L_2;
		// Regions.Add(new RegionPointer(interiorPoint.X, interiorPoint.Y, regionlabel));
		List_1_tC9803D99D64F5D893C71690F4B65415B86B42629* L_3;
		L_3 = Polygon_get_Regions_m660FF6A0859225FB2AAC663ED02B6679B866CC43_inline(__this, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_4 = V_0;
		NullCheck(L_4);
		double L_5;
		L_5 = Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline(L_4, NULL);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_6 = V_0;
		NullCheck(L_6);
		double L_7;
		L_7 = Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline(L_6, NULL);
		int32_t L_8 = ___1_regionlabel;
		RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* L_9 = (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B*)il2cpp_codegen_object_new(RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B_il2cpp_TypeInfo_var);
		NullCheck(L_9);
		RegionPointer__ctor_mAFFA818BD752BBEDF313C606A15989706779A45B(L_9, L_5, L_7, L_8, NULL);
		NullCheck(L_3);
		List_1_Add_mDF33EBADE6B533124F05BADC13B657B09BA0A931_inline(L_3, L_9, List_1_Add_mDF33EBADE6B533124F05BADC13B657B09BA0A931_RuntimeMethod_var);
	}

IL_0031:
	{
		// AddContourPointsAndSegments(contour);
		Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* L_10 = ___0_contour;
		Polygon_AddContourPointsAndSegments_m1C3789D2CF4448291C1335664C7B2BE9E11DCA8B(__this, L_10, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Polygon::Add(TriangleNet.Geometry.Contour,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_Add_m365ACF84CDE140D949AEB96A23B93E41796A8D79 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* ___0_contour, bool ___1_hole, const RuntimeMethod* method) 
{
	{
		// if (hole)
		bool L_0 = ___1_hole;
		if (!L_0)
		{
			goto IL_001b;
		}
	}
	{
		// Add(contour, contour.FindInteriorPoint());
		Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* L_1 = ___0_contour;
		Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* L_2 = ___0_contour;
		NullCheck(L_2);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_3;
		L_3 = Contour_FindInteriorPoint_m405B8515C17A404A24B40398F1390C050BE380B1(L_2, 5, (2.0000000000000002E-05), NULL);
		Polygon_Add_mB07D1D1781C87FCDEC98322A9804357826BE7F67(__this, L_1, L_3, NULL);
		return;
	}

IL_001b:
	{
		// AddContourPointsAndSegments(contour);
		Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* L_4 = ___0_contour;
		Polygon_AddContourPointsAndSegments_m1C3789D2CF4448291C1335664C7B2BE9E11DCA8B(__this, L_4, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Polygon::Add(TriangleNet.Geometry.Contour,TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Polygon_Add_mB07D1D1781C87FCDEC98322A9804357826BE7F67 (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* ___0_contour, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___1_hole, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mA8954CBD8FEAD083744D6ED57632DA1748BB6219_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// AddContourPointsAndSegments(contour);
		Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* L_0 = ___0_contour;
		Polygon_AddContourPointsAndSegments_m1C3789D2CF4448291C1335664C7B2BE9E11DCA8B(__this, L_0, NULL);
		// holes.Add(hole);
		List_1_t53B2F2B68D5C33A02009754AF59499A665EDB5BE* L_1 = __this->___holes_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_2 = ___1_hole;
		NullCheck(L_1);
		List_1_Add_mA8954CBD8FEAD083744D6ED57632DA1748BB6219_inline(L_1, L_2, List_1_Add_mA8954CBD8FEAD083744D6ED57632DA1748BB6219_RuntimeMethod_var);
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void TriangleNet.Geometry.Rectangle::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle__ctor_m826E64394C092D2A9D743261E2A10E22F9697FD6 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	double V_0 = 0.0;
	{
		// public Rectangle()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// xmin = ymin = double.MaxValue;
		double L_0 = (1.7976931348623157E+308);
		V_0 = L_0;
		__this->___ymin_1 = L_0;
		double L_1 = V_0;
		__this->___xmin_0 = L_1;
		// xmax = ymax = -double.MaxValue;
		double L_2 = (-1.7976931348623157E+308);
		V_0 = L_2;
		__this->___ymax_3 = L_2;
		double L_3 = V_0;
		__this->___xmax_2 = L_3;
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Rectangle::.ctor(TriangleNet.Geometry.Rectangle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle__ctor_mEB5F989E556EEFABD9279BE924F0EA41A06141D3 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* ___0_other, const RuntimeMethod* method) 
{
	{
		// : this(other.Left, other.Bottom, other.Right, other.Top)
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_0 = ___0_other;
		NullCheck(L_0);
		double L_1;
		L_1 = Rectangle_get_Left_mD51F75017ABFAB864FCFFA000654BAD8B69C0095_inline(L_0, NULL);
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_2 = ___0_other;
		NullCheck(L_2);
		double L_3;
		L_3 = Rectangle_get_Bottom_m50E053BB79DB47EACE3D76FCB9B9838691C831FC_inline(L_2, NULL);
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_4 = ___0_other;
		NullCheck(L_4);
		double L_5;
		L_5 = Rectangle_get_Right_m66D5AC49665B4ACF7E583D0DB180067C7275343D_inline(L_4, NULL);
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_6 = ___0_other;
		NullCheck(L_6);
		double L_7;
		L_7 = Rectangle_get_Top_mB5BBC0F6EF84C1DA34190080747C466F1465E64A_inline(L_6, NULL);
		Rectangle__ctor_mA1636D5D1554237F24B5FCBE65092D98F85CC53D(__this, L_1, L_3, L_5, L_7, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Rectangle::.ctor(System.Double,System.Double,System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle__ctor_mA1636D5D1554237F24B5FCBE65092D98F85CC53D (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, double ___0_x, double ___1_y, double ___2_width, double ___3_height, const RuntimeMethod* method) 
{
	{
		// public Rectangle(double x, double y, double width, double height)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// xmin = x;
		double L_0 = ___0_x;
		__this->___xmin_0 = L_0;
		// ymin = y;
		double L_1 = ___1_y;
		__this->___ymin_1 = L_1;
		// xmax = x + width;
		double L_2 = ___0_x;
		double L_3 = ___2_width;
		__this->___xmax_2 = ((double)il2cpp_codegen_add(L_2, L_3));
		// ymax = y + height;
		double L_4 = ___1_y;
		double L_5 = ___3_height;
		__this->___ymax_3 = ((double)il2cpp_codegen_add(L_4, L_5));
		// }
		return;
	}
}
// System.Double TriangleNet.Geometry.Rectangle::get_Left()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Rectangle_get_Left_mD51F75017ABFAB864FCFFA000654BAD8B69C0095 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Left => xmin;
		double L_0 = __this->___xmin_0;
		return L_0;
	}
}
// System.Double TriangleNet.Geometry.Rectangle::get_Right()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Rectangle_get_Right_m66D5AC49665B4ACF7E583D0DB180067C7275343D (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Right => xmax;
		double L_0 = __this->___xmax_2;
		return L_0;
	}
}
// System.Double TriangleNet.Geometry.Rectangle::get_Bottom()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Rectangle_get_Bottom_m50E053BB79DB47EACE3D76FCB9B9838691C831FC (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Bottom => ymin;
		double L_0 = __this->___ymin_1;
		return L_0;
	}
}
// System.Double TriangleNet.Geometry.Rectangle::get_Top()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Rectangle_get_Top_mB5BBC0F6EF84C1DA34190080747C466F1465E64A (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Top => ymax;
		double L_0 = __this->___ymax_3;
		return L_0;
	}
}
// System.Double TriangleNet.Geometry.Rectangle::get_X()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Rectangle_get_X_m97965F76BFCAC12FCF47510AFE7099E16D06C667 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double X => xmin;
		double L_0 = __this->___xmin_0;
		return L_0;
	}
}
// System.Double TriangleNet.Geometry.Rectangle::get_Y()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Rectangle_get_Y_m27E114C6ED1FB388F6C819E81D276FE8D4F328CD (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Y => ymin;
		double L_0 = __this->___ymin_1;
		return L_0;
	}
}
// System.Double TriangleNet.Geometry.Rectangle::get_Width()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Rectangle_get_Width_m23F0178934618D1365BCEBF1E9395D62F47C2854 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Width => xmax - xmin;
		double L_0 = __this->___xmax_2;
		double L_1 = __this->___xmin_0;
		return ((double)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// System.Double TriangleNet.Geometry.Rectangle::get_Height()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Rectangle_get_Height_m04DBB248BD48F7110DBCB31E96983C7D0E2A7DE1 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Height => ymax - ymin;
		double L_0 = __this->___ymax_3;
		double L_1 = __this->___ymin_1;
		return ((double)il2cpp_codegen_subtract(L_0, L_1));
	}
}
// System.Void TriangleNet.Geometry.Rectangle::Resize(System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle_Resize_m11448C90EA89FE915AF879656BC0CB7EB9648DDA (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, double ___0_dx, double ___1_dy, const RuntimeMethod* method) 
{
	{
		// xmin -= dx;
		double L_0 = __this->___xmin_0;
		double L_1 = ___0_dx;
		__this->___xmin_0 = ((double)il2cpp_codegen_subtract(L_0, L_1));
		// xmax += dx;
		double L_2 = __this->___xmax_2;
		double L_3 = ___0_dx;
		__this->___xmax_2 = ((double)il2cpp_codegen_add(L_2, L_3));
		// ymin -= dy;
		double L_4 = __this->___ymin_1;
		double L_5 = ___1_dy;
		__this->___ymin_1 = ((double)il2cpp_codegen_subtract(L_4, L_5));
		// ymax += dy;
		double L_6 = __this->___ymax_3;
		double L_7 = ___1_dy;
		__this->___ymax_3 = ((double)il2cpp_codegen_add(L_6, L_7));
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Rectangle::Expand(TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle_Expand_mB0DC57451EAFE5F38DAAB3C29CBD577977A4200B (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_p, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// xmin = Math.Min(xmin, p.x);
		double L_0 = __this->___xmin_0;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_1 = ___0_p;
		NullCheck(L_1);
		double L_2 = L_1->___x_2;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_3;
		L_3 = Math_Min_mA3310F1FF7876DA2FC7F37B822E6DD66410565C1(L_0, L_2, NULL);
		__this->___xmin_0 = L_3;
		// ymin = Math.Min(ymin, p.y);
		double L_4 = __this->___ymin_1;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_5 = ___0_p;
		NullCheck(L_5);
		double L_6 = L_5->___y_3;
		double L_7;
		L_7 = Math_Min_mA3310F1FF7876DA2FC7F37B822E6DD66410565C1(L_4, L_6, NULL);
		__this->___ymin_1 = L_7;
		// xmax = Math.Max(xmax, p.x);
		double L_8 = __this->___xmax_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_9 = ___0_p;
		NullCheck(L_9);
		double L_10 = L_9->___x_2;
		double L_11;
		L_11 = Math_Max_m7BAC743E1752A51F258BB82DEBDD13E7C6D3ED26(L_8, L_10, NULL);
		__this->___xmax_2 = L_11;
		// ymax = Math.Max(ymax, p.y);
		double L_12 = __this->___ymax_3;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_13 = ___0_p;
		NullCheck(L_13);
		double L_14 = L_13->___y_3;
		double L_15;
		L_15 = Math_Max_m7BAC743E1752A51F258BB82DEBDD13E7C6D3ED26(L_12, L_14, NULL);
		__this->___ymax_3 = L_15;
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Rectangle::Expand(System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Point>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle_Expand_m866BD091569A256E1E06FC3E6B3627DFC125FDD7 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, RuntimeObject* ___0_points, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_1_t5574BA1E7B453137C3580B21A7126DFCBDA331BE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_1_t357504A725D78F0BC68EA02C72449D4F927A758F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* V_1 = NULL;
	{
		// foreach (var p in points)
		RuntimeObject* L_0 = ___0_points;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0 /* System.Collections.Generic.IEnumerator`1<T> System.Collections.Generic.IEnumerable`1<TriangleNet.Geometry.Point>::GetEnumerator() */, IEnumerable_1_t5574BA1E7B453137C3580B21A7126DFCBDA331BE_il2cpp_TypeInfo_var, L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0021:
			{// begin finally (depth: 1)
				{
					RuntimeObject* L_2 = V_0;
					if (!L_2)
					{
						goto IL_002a;
					}
				}
				{
					RuntimeObject* L_3 = V_0;
					NullCheck(L_3);
					InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_3);
				}

IL_002a:
				{
					return;
				}
			}// end finally (depth: 1)
		});
		try
		{// begin try (depth: 1)
			{
				goto IL_0017_1;
			}

IL_0009_1:
			{
				// foreach (var p in points)
				RuntimeObject* L_4 = V_0;
				NullCheck(L_4);
				Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_5;
				L_5 = InterfaceFuncInvoker0< Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* >::Invoke(0 /* T System.Collections.Generic.IEnumerator`1<TriangleNet.Geometry.Point>::get_Current() */, IEnumerator_1_t357504A725D78F0BC68EA02C72449D4F927A758F_il2cpp_TypeInfo_var, L_4);
				V_1 = L_5;
				// Expand(p);
				Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_6 = V_1;
				Rectangle_Expand_mB0DC57451EAFE5F38DAAB3C29CBD577977A4200B(__this, L_6, NULL);
			}

IL_0017_1:
			{
				// foreach (var p in points)
				RuntimeObject* L_7 = V_0;
				NullCheck(L_7);
				bool L_8;
				L_8 = InterfaceFuncInvoker0< bool >::Invoke(0 /* System.Boolean System.Collections.IEnumerator::MoveNext() */, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_7);
				if (L_8)
				{
					goto IL_0009_1;
				}
			}
			{
				goto IL_002b;
			}
		}// end try (depth: 1)
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_002b:
	{
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Rectangle::Expand(TriangleNet.Geometry.Rectangle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rectangle_Expand_m4E28DC925CF0D801126000DD0C81EA47ACF42943 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* ___0_other, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// xmin = Math.Min(xmin, other.xmin);
		double L_0 = __this->___xmin_0;
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_1 = ___0_other;
		NullCheck(L_1);
		double L_2 = L_1->___xmin_0;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_3;
		L_3 = Math_Min_mA3310F1FF7876DA2FC7F37B822E6DD66410565C1(L_0, L_2, NULL);
		__this->___xmin_0 = L_3;
		// ymin = Math.Min(ymin, other.ymin);
		double L_4 = __this->___ymin_1;
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_5 = ___0_other;
		NullCheck(L_5);
		double L_6 = L_5->___ymin_1;
		double L_7;
		L_7 = Math_Min_mA3310F1FF7876DA2FC7F37B822E6DD66410565C1(L_4, L_6, NULL);
		__this->___ymin_1 = L_7;
		// xmax = Math.Max(xmax, other.xmax);
		double L_8 = __this->___xmax_2;
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_9 = ___0_other;
		NullCheck(L_9);
		double L_10 = L_9->___xmax_2;
		double L_11;
		L_11 = Math_Max_m7BAC743E1752A51F258BB82DEBDD13E7C6D3ED26(L_8, L_10, NULL);
		__this->___xmax_2 = L_11;
		// ymax = Math.Max(ymax, other.ymax);
		double L_12 = __this->___ymax_3;
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_13 = ___0_other;
		NullCheck(L_13);
		double L_14 = L_13->___ymax_3;
		double L_15;
		L_15 = Math_Max_m7BAC743E1752A51F258BB82DEBDD13E7C6D3ED26(L_12, L_14, NULL);
		__this->___ymax_3 = L_15;
		// }
		return;
	}
}
// System.Boolean TriangleNet.Geometry.Rectangle::Contains(System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Rectangle_Contains_m9F847EC58CA335E2B9B453C6DD39604C8E903232 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, double ___0_x, double ___1_y, const RuntimeMethod* method) 
{
	{
		// return (x >= xmin) && (x <= xmax) && (y >= ymin) && (y <= ymax);
		double L_0 = ___0_x;
		double L_1 = __this->___xmin_0;
		if ((!(((double)L_0) >= ((double)L_1))))
		{
			goto IL_0028;
		}
	}
	{
		double L_2 = ___0_x;
		double L_3 = __this->___xmax_2;
		if ((!(((double)L_2) <= ((double)L_3))))
		{
			goto IL_0028;
		}
	}
	{
		double L_4 = ___1_y;
		double L_5 = __this->___ymin_1;
		if ((!(((double)L_4) >= ((double)L_5))))
		{
			goto IL_0028;
		}
	}
	{
		double L_6 = ___1_y;
		double L_7 = __this->___ymax_3;
		return (bool)((((int32_t)((!(((double)L_6) <= ((double)L_7)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0028:
	{
		return (bool)0;
	}
}
// System.Boolean TriangleNet.Geometry.Rectangle::Contains(TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Rectangle_Contains_mE8BE1E8DFEBE3EF1784CFCFB3C93DF2809A87197 (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_pt, const RuntimeMethod* method) 
{
	{
		// return Contains(pt.x, pt.y);
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_0 = ___0_pt;
		NullCheck(L_0);
		double L_1 = L_0->___x_2;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_2 = ___0_pt;
		NullCheck(L_2);
		double L_3 = L_2->___y_3;
		bool L_4;
		L_4 = Rectangle_Contains_m9F847EC58CA335E2B9B453C6DD39604C8E903232(__this, L_1, L_3, NULL);
		return L_4;
	}
}
// System.Boolean TriangleNet.Geometry.Rectangle::Contains(TriangleNet.Geometry.Rectangle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Rectangle_Contains_m36AEB0898A8A9005B6F22BAC726F7551D57D19AF (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* ___0_other, const RuntimeMethod* method) 
{
	{
		// return xmin <= other.Left && other.Right <= xmax
		//     && ymin <= other.Bottom && other.Top <= ymax;
		double L_0 = __this->___xmin_0;
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_1 = ___0_other;
		NullCheck(L_1);
		double L_2;
		L_2 = Rectangle_get_Left_mD51F75017ABFAB864FCFFA000654BAD8B69C0095_inline(L_1, NULL);
		if ((!(((double)L_0) <= ((double)L_2))))
		{
			goto IL_003c;
		}
	}
	{
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_3 = ___0_other;
		NullCheck(L_3);
		double L_4;
		L_4 = Rectangle_get_Right_m66D5AC49665B4ACF7E583D0DB180067C7275343D_inline(L_3, NULL);
		double L_5 = __this->___xmax_2;
		if ((!(((double)L_4) <= ((double)L_5))))
		{
			goto IL_003c;
		}
	}
	{
		double L_6 = __this->___ymin_1;
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_7 = ___0_other;
		NullCheck(L_7);
		double L_8;
		L_8 = Rectangle_get_Bottom_m50E053BB79DB47EACE3D76FCB9B9838691C831FC_inline(L_7, NULL);
		if ((!(((double)L_6) <= ((double)L_8))))
		{
			goto IL_003c;
		}
	}
	{
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_9 = ___0_other;
		NullCheck(L_9);
		double L_10;
		L_10 = Rectangle_get_Top_mB5BBC0F6EF84C1DA34190080747C466F1465E64A_inline(L_9, NULL);
		double L_11 = __this->___ymax_3;
		return (bool)((((int32_t)((!(((double)L_10) <= ((double)L_11)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_003c:
	{
		return (bool)0;
	}
}
// System.Boolean TriangleNet.Geometry.Rectangle::Intersects(TriangleNet.Geometry.Rectangle)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Rectangle_Intersects_m44039CE3AB958DF11550CBB786292B3F61B44A3C (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* ___0_other, const RuntimeMethod* method) 
{
	{
		// return other.Left < xmax && xmin < other.Right
		//     && other.Bottom < ymax && ymin < other.Top;
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_0 = ___0_other;
		NullCheck(L_0);
		double L_1;
		L_1 = Rectangle_get_Left_mD51F75017ABFAB864FCFFA000654BAD8B69C0095_inline(L_0, NULL);
		double L_2 = __this->___xmax_2;
		if ((!(((double)L_1) < ((double)L_2))))
		{
			goto IL_0039;
		}
	}
	{
		double L_3 = __this->___xmin_0;
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_4 = ___0_other;
		NullCheck(L_4);
		double L_5;
		L_5 = Rectangle_get_Right_m66D5AC49665B4ACF7E583D0DB180067C7275343D_inline(L_4, NULL);
		if ((!(((double)L_3) < ((double)L_5))))
		{
			goto IL_0039;
		}
	}
	{
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_6 = ___0_other;
		NullCheck(L_6);
		double L_7;
		L_7 = Rectangle_get_Bottom_m50E053BB79DB47EACE3D76FCB9B9838691C831FC_inline(L_6, NULL);
		double L_8 = __this->___ymax_3;
		if ((!(((double)L_7) < ((double)L_8))))
		{
			goto IL_0039;
		}
	}
	{
		double L_9 = __this->___ymin_1;
		Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* L_10 = ___0_other;
		NullCheck(L_10);
		double L_11;
		L_11 = Rectangle_get_Top_mB5BBC0F6EF84C1DA34190080747C466F1465E64A_inline(L_10, NULL);
		return (bool)((((double)L_9) < ((double)L_11))? 1 : 0);
	}

IL_0039:
	{
		return (bool)0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// TriangleNet.Geometry.Point TriangleNet.Geometry.RegionPointer::get_Point()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* RegionPointer_get_Point_mBE5C186113E72B5903EA37A0D775E652B9BA9188 (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, const RuntimeMethod* method) 
{
	{
		// public Point Point { get; private set; }
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_0 = __this->___U3CPointU3Ek__BackingField_0;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.RegionPointer::set_Point(TriangleNet.Geometry.Point)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RegionPointer_set_Point_m16F2E59D9B4E72763D33C77452AFB4504607403F (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_value, const RuntimeMethod* method) 
{
	{
		// public Point Point { get; private set; }
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_0 = ___0_value;
		__this->___U3CPointU3Ek__BackingField_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CPointU3Ek__BackingField_0), (void*)L_0);
		return;
	}
}
// System.Int32 TriangleNet.Geometry.RegionPointer::get_Label()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t RegionPointer_get_Label_mC0827A4F7A00A7D0D377D582EF52D36B0B8A220F (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, const RuntimeMethod* method) 
{
	{
		// public int Label { get; private set; }
		int32_t L_0 = __this->___U3CLabelU3Ek__BackingField_1;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.RegionPointer::set_Label(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RegionPointer_set_Label_mCF3674DA129C2F8F5B943A496E2696664CF17235 (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int Label { get; private set; }
		int32_t L_0 = ___0_value;
		__this->___U3CLabelU3Ek__BackingField_1 = L_0;
		return;
	}
}
// System.Double TriangleNet.Geometry.RegionPointer::get_Area()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double RegionPointer_get_Area_m4C6BE47C81FEC0F7C40493D7020C0C1EF10F3F85 (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, const RuntimeMethod* method) 
{
	{
		// public double Area { get; private set; }
		double L_0 = __this->___U3CAreaU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.RegionPointer::set_Area(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RegionPointer_set_Area_mEA8344CA85F6CD0E5FBF6B013692B653F48782A7 (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, double ___0_value, const RuntimeMethod* method) 
{
	{
		// public double Area { get; private set; }
		double L_0 = ___0_value;
		__this->___U3CAreaU3Ek__BackingField_2 = L_0;
		return;
	}
}
// System.Void TriangleNet.Geometry.RegionPointer::.ctor(System.Double,System.Double,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RegionPointer__ctor_mAFFA818BD752BBEDF313C606A15989706779A45B (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, double ___0_x, double ___1_y, int32_t ___2_label, const RuntimeMethod* method) 
{
	{
		// : this(x, y, label, 0.0)
		double L_0 = ___0_x;
		double L_1 = ___1_y;
		int32_t L_2 = ___2_label;
		RegionPointer__ctor_mB49AB58BE1A3D3F40469BA9F733C76D2E826A40A(__this, L_0, L_1, L_2, (0.0), NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.RegionPointer::.ctor(System.Double,System.Double,System.Int32,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RegionPointer__ctor_mB49AB58BE1A3D3F40469BA9F733C76D2E826A40A (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, double ___0_x, double ___1_y, int32_t ___2_label, double ___3_area, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public RegionPointer(double x, double y, int label, double area)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// Point = new Point(x, y);
		double L_0 = ___0_x;
		double L_1 = ___1_y;
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_2 = (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)il2cpp_codegen_object_new(Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		Point__ctor_m36BE66184AB548B99409ADDD4178D0019D4E0289(L_2, L_0, L_1, NULL);
		RegionPointer_set_Point_m16F2E59D9B4E72763D33C77452AFB4504607403F_inline(__this, L_2, NULL);
		// Label = label;
		int32_t L_3 = ___2_label;
		RegionPointer_set_Label_mCF3674DA129C2F8F5B943A496E2696664CF17235_inline(__this, L_3, NULL);
		// Area = area;
		double L_4 = ___3_area;
		RegionPointer_set_Area_mEA8344CA85F6CD0E5FBF6B013692B653F48782A7_inline(__this, L_4, NULL);
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Int32 TriangleNet.Geometry.Segment::get_Label()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Segment_get_Label_mB3316F87DF1A3667A37B936C791F72C536360D29 (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, const RuntimeMethod* method) 
{
	{
		// public int Label { get; set; }
		int32_t L_0 = __this->___U3CLabelU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void TriangleNet.Geometry.Segment::set_Label(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Segment_set_Label_mD44E71611259407699FE53DC530AD01E9F25FC79 (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int Label { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CLabelU3Ek__BackingField_2 = L_0;
		return;
	}
}
// System.Int32 TriangleNet.Geometry.Segment::get_P0()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Segment_get_P0_m095A7D2BCEEDFB198F8B764813E65B5A083E9741 (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, const RuntimeMethod* method) 
{
	{
		// public int P0 => v0.id;
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_0 = __this->___v0_0;
		NullCheck(L_0);
		int32_t L_1 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_0)->___id_0;
		return L_1;
	}
}
// System.Int32 TriangleNet.Geometry.Segment::get_P1()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Segment_get_P1_mF4CB17CBC07ECECFDED04989D9C928920C4D096E (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, const RuntimeMethod* method) 
{
	{
		// public int P1 => v1.id;
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_0 = __this->___v1_1;
		NullCheck(L_0);
		int32_t L_1 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)L_0)->___id_0;
		return L_1;
	}
}
// System.Void TriangleNet.Geometry.Segment::.ctor(TriangleNet.Geometry.Vertex,TriangleNet.Geometry.Vertex)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Segment__ctor_m206E209226169A53E9B7DFC0EE0544A8CF584AD0 (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* ___0_v0, Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* ___1_v1, const RuntimeMethod* method) 
{
	{
		// : this (v0, v1, 0)
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_0 = ___0_v0;
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_1 = ___1_v1;
		Segment__ctor_mDC03832F4F3F9FDC8C8F8EFAE7B86DA5579DB0DF(__this, L_0, L_1, 0, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Segment::.ctor(TriangleNet.Geometry.Vertex,TriangleNet.Geometry.Vertex,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Segment__ctor_mDC03832F4F3F9FDC8C8F8EFAE7B86DA5579DB0DF (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* ___0_v0, Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* ___1_v1, int32_t ___2_label, const RuntimeMethod* method) 
{
	{
		// public Segment(Vertex v0, Vertex v1, int label)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// this.v0 = v0;
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_0 = ___0_v0;
		__this->___v0_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___v0_0), (void*)L_0);
		// this.v1 = v1;
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_1 = ___1_v1;
		__this->___v1_1 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___v1_1), (void*)L_1);
		// Label = label;
		int32_t L_2 = ___2_label;
		Segment_set_Label_mD44E71611259407699FE53DC530AD01E9F25FC79_inline(__this, L_2, NULL);
		// }
		return;
	}
}
// TriangleNet.Geometry.Vertex TriangleNet.Geometry.Segment::GetVertex(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* Segment_GetVertex_m6C0556367EEAF733310FAC17B5A25FC9C9F9186E (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		// if (index == 0) return v0;
		int32_t L_0 = ___0_index;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		// if (index == 0) return v0;
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_1 = __this->___v0_0;
		return L_1;
	}

IL_000a:
	{
		// if (index == 1) return v1;
		int32_t L_2 = ___0_index;
		if ((!(((uint32_t)L_2) == ((uint32_t)1))))
		{
			goto IL_0015;
		}
	}
	{
		// if (index == 1) return v1;
		Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* L_3 = __this->___v1_1;
		return L_3;
	}

IL_0015:
	{
		// throw new IndexOutOfRangeException();
		IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82* L_4 = (IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82_il2cpp_TypeInfo_var)));
		NullCheck(L_4);
		IndexOutOfRangeException__ctor_m270ED9671475CE680EEA8C62A7A43308AE4188EF(L_4, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Segment_GetVertex_m6C0556367EEAF733310FAC17B5A25FC9C9F9186E_RuntimeMethod_var)));
	}
}
// TriangleNet.Geometry.ITriangle TriangleNet.Geometry.Segment::GetTriangle(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Segment_GetTriangle_m899F4C9637B3F2F5C91DC5EE4494DC2B96BE0C6E (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		// throw new NotImplementedException();
		NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8* L_0 = (NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8_il2cpp_TypeInfo_var)));
		NullCheck(L_0);
		NotImplementedException__ctor_mDAB47BC6BD0E342E8F2171E5CABE3E67EA049F1C(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Segment_GetTriangle_m899F4C9637B3F2F5C91DC5EE4494DC2B96BE0C6E_RuntimeMethod_var)));
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void TriangleNet.Geometry.Vertex::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vertex__ctor_m5A31515221AFF26C5CD2208A9792A65C19DA852E (Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* __this, const RuntimeMethod* method) 
{
	{
		// : this(0, 0, 0)
		Vertex__ctor_mF5813341873B36A8E49E6030D2ED1A55073FE545(__this, (0.0), (0.0), 0, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Vertex::.ctor(System.Double,System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vertex__ctor_m628B26B18E1797B7418D9F9E7637669FC8222CE5 (Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* __this, double ___0_x, double ___1_y, const RuntimeMethod* method) 
{
	{
		// : this(x, y, 0)
		double L_0 = ___0_x;
		double L_1 = ___1_y;
		Vertex__ctor_mF5813341873B36A8E49E6030D2ED1A55073FE545(__this, L_0, L_1, 0, NULL);
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Vertex::.ctor(System.Double,System.Double,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vertex__ctor_mF5813341873B36A8E49E6030D2ED1A55073FE545 (Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* __this, double ___0_x, double ___1_y, int32_t ___2_mark, const RuntimeMethod* method) 
{
	{
		// : base(x, y, mark)
		double L_0 = ___0_x;
		double L_1 = ___1_y;
		int32_t L_2 = ___2_mark;
		Point__ctor_m6F9D396D184EC6C20BF40C449AB7964256A0C863(__this, L_0, L_1, L_2, NULL);
		// type = VertexType.InputVertex;
		__this->___type_5 = 0;
		// }
		return;
	}
}
// System.Void TriangleNet.Geometry.Vertex::.ctor(System.Double,System.Double,System.Int32,TriangleNet.VertexType)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vertex__ctor_mCD9484427E96F697B4DDB5E3228298ABBF99BABB (Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* __this, double ___0_x, double ___1_y, int32_t ___2_mark, int32_t ___3_type, const RuntimeMethod* method) 
{
	{
		// : base(x, y, mark)
		double L_0 = ___0_x;
		double L_1 = ___1_y;
		int32_t L_2 = ___2_mark;
		Point__ctor_m6F9D396D184EC6C20BF40C449AB7964256A0C863(__this, L_0, L_1, L_2, NULL);
		// this.type = type;
		int32_t L_3 = ___3_type;
		__this->___type_5 = L_3;
		// }
		return;
	}
}
// TriangleNet.VertexType TriangleNet.Geometry.Vertex::get_Type()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vertex_get_Type_m46C449F45310C0657C28C826397AE314297AF978 (Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* __this, const RuntimeMethod* method) 
{
	{
		// public VertexType Type => type;
		int32_t L_0 = __this->___type_5;
		return L_0;
	}
}
// System.Double TriangleNet.Geometry.Vertex::get_Item(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Vertex_get_Item_mD277E990CF8ABA774434CFC508638CEEF54458CE (Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* __this, int32_t ___0_i, const RuntimeMethod* method) 
{
	{
		// if (i == 0) return x;
		int32_t L_0 = ___0_i;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		// if (i == 0) return x;
		double L_1 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)__this)->___x_2;
		return L_1;
	}

IL_000a:
	{
		// if (i == 1) return y;
		int32_t L_2 = ___0_i;
		if ((!(((uint32_t)L_2) == ((uint32_t)1))))
		{
			goto IL_0015;
		}
	}
	{
		// if (i == 1) return y;
		double L_3 = ((Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1*)__this)->___y_3;
		return L_3;
	}

IL_0015:
	{
		// throw new ArgumentOutOfRangeException("Index must be 0 or 1.");
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		NullCheck(L_4);
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE514E1AE1B1F65BD7549E260248926108E125A19)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Vertex_get_Item_mD277E990CF8ABA774434CFC508638CEEF54458CE_RuntimeMethod_var)));
	}
}
// System.Int32 TriangleNet.Geometry.Vertex::GetHashCode()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vertex_GetHashCode_m7616B92765737C47787EDB480645F1D8B940D444 (Vertex_t3659D3E3B43226A64C6C54A4DC77E4CC00B59B6A* __this, const RuntimeMethod* method) 
{
	{
		// public override int GetHashCode() => hash;
		int32_t L_0 = __this->___hash_4;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* Contour_get_Points_m50EBF37050AA499D0D68AB42C3D346386A18ED07_inline (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, const RuntimeMethod* method) 
{
	{
		// public List<Vertex> Points { get; set; }
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_0 = __this->___U3CPointsU3Ek__BackingField_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Contour_set_Points_mBA0FAB674F747150769FB8A1FB62D129A1ED3179_inline (Contour_t70659C3E8B022C27A2D1C63B72657BAA82D43087* __this, List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* ___0_value, const RuntimeMethod* method) 
{
	{
		// public List<Vertex> Points { get; set; }
		List_1_tBC88BF9F63B2BA49DD3FF619542C9A5C6506963C* L_0 = ___0_value;
		__this->___U3CPointsU3Ek__BackingField_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CPointsU3Ek__BackingField_2), (void*)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Edge_set_P0_mB0616BBD1AF6210443FF8BF3F3C81F9DDC5728EA_inline (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int P0 { get; private set; }
		int32_t L_0 = ___0_value;
		__this->___U3CP0U3Ek__BackingField_0 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Edge_set_P1_m35B336CD05909FEEE165A4FF77DCDF554D0653E5_inline (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int P1 { get; private set; }
		int32_t L_0 = ___0_value;
		__this->___U3CP1U3Ek__BackingField_1 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Edge_set_Label_m2CCB72689E3B178FC25C8BDDEC3334E1D3FF101F_inline (Edge_t5072708FD6F008D1384941B58A8BC75A3A56ED64* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int Label { get; private set; }
		int32_t L_0 = ___0_value;
		__this->___U3CLabelU3Ek__BackingField_2 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Point_get_X_mD625CBA9C6A9648C4D948BB5B98660F868AABB8B_inline (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) 
{
	{
		// get { return x; }
		double L_0 = __this->___x_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Point_get_Y_mD6CB499511229223031BDA7060341E1331D0E24C_inline (Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* __this, const RuntimeMethod* method) 
{
	{
		// get { return y; }
		double L_0 = __this->___y_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline (double* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int64_t V_0 = 0;
	{
		double L_0 = *((double*)__this);
		il2cpp_codegen_runtime_class_init_inline(BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var);
		int64_t L_1;
		L_1 = BitConverter_DoubleToInt64Bits_m4F42741818550F9956B5FBAF88C051F4DE5B0AE6_inline(L_0, NULL);
		V_0 = L_1;
		int64_t L_2 = V_0;
		if ((((int64_t)((int64_t)(((int64_t)il2cpp_codegen_subtract(L_2, ((int64_t)1)))&((int64_t)(std::numeric_limits<int64_t>::max)())))) < ((int64_t)((int64_t)9218868437227405312LL))))
		{
			goto IL_002d;
		}
	}
	{
		int64_t L_3 = V_0;
		V_0 = ((int64_t)(L_3&((int64_t)9218868437227405312LL)));
	}

IL_002d:
	{
		int64_t L_4 = V_0;
		int64_t L_5 = V_0;
		return ((int32_t)(((int32_t)L_4)^((int32_t)((int64_t)(L_5>>((int32_t)32))))));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Polygon_set_HasPointMarkers_m18685DE71EEBCC7E72D83FBDF5B812610C25E51A_inline (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// public bool HasPointMarkers { get; set; }
		bool L_0 = ___0_value;
		__this->___U3CHasPointMarkersU3Ek__BackingField_4 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Polygon_set_HasSegmentMarkers_mCCFDDD29B78E8945420060057599DA63DB064B38_inline (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		// public bool HasSegmentMarkers { get; set; }
		bool L_0 = ___0_value;
		__this->___U3CHasSegmentMarkersU3Ek__BackingField_5 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR List_1_tC9803D99D64F5D893C71690F4B65415B86B42629* Polygon_get_Regions_m660FF6A0859225FB2AAC663ED02B6679B866CC43_inline (Polygon_tB23BB11E6268B080B64D2CDB00573FE3EC4BBDF2* __this, const RuntimeMethod* method) 
{
	{
		// public List<RegionPointer> Regions => regions;
		List_1_tC9803D99D64F5D893C71690F4B65415B86B42629* L_0 = __this->___regions_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Rectangle_get_Left_mD51F75017ABFAB864FCFFA000654BAD8B69C0095_inline (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Left => xmin;
		double L_0 = __this->___xmin_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Rectangle_get_Bottom_m50E053BB79DB47EACE3D76FCB9B9838691C831FC_inline (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Bottom => ymin;
		double L_0 = __this->___ymin_1;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Rectangle_get_Right_m66D5AC49665B4ACF7E583D0DB180067C7275343D_inline (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Right => xmax;
		double L_0 = __this->___xmax_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Rectangle_get_Top_mB5BBC0F6EF84C1DA34190080747C466F1465E64A_inline (Rectangle_tC7919C8B8B93BE710EF88C264E77C89B9257926B* __this, const RuntimeMethod* method) 
{
	{
		// public double Top => ymax;
		double L_0 = __this->___ymax_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RegionPointer_set_Point_m16F2E59D9B4E72763D33C77452AFB4504607403F_inline (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* ___0_value, const RuntimeMethod* method) 
{
	{
		// public Point Point { get; private set; }
		Point_t09C9754C4C9F2CDBA5ACF6F7ED1D42E5CABCD8B1* L_0 = ___0_value;
		__this->___U3CPointU3Ek__BackingField_0 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CPointU3Ek__BackingField_0), (void*)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RegionPointer_set_Label_mCF3674DA129C2F8F5B943A496E2696664CF17235_inline (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int Label { get; private set; }
		int32_t L_0 = ___0_value;
		__this->___U3CLabelU3Ek__BackingField_1 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void RegionPointer_set_Area_mEA8344CA85F6CD0E5FBF6B013692B653F48782A7_inline (RegionPointer_t2555A435FB3922BF9B45C89E008B7CEF2132CA6B* __this, double ___0_value, const RuntimeMethod* method) 
{
	{
		// public double Area { get; private set; }
		double L_0 = ___0_value;
		__this->___U3CAreaU3Ek__BackingField_2 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Segment_set_Label_mD44E71611259407699FE53DC530AD01E9F25FC79_inline (Segment_tFE884D853F1A6981EAEE453AE965A09F7715FD7E* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		// public int Label { get; set; }
		int32_t L_0 = ___0_value;
		__this->___U3CLabelU3Ek__BackingField_2 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version_3;
		__this->____version_3 = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->____items_1;
		V_0 = L_1;
		int32_t L_2 = __this->____size_2;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size_2 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_6 = V_0;
		int32_t L_7 = V_1;
		RuntimeObject* L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (RuntimeObject*)L_8);
		return;
	}

IL_0034:
	{
		RuntimeObject* L_9 = ___0_item;
		((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_method_pointer(il2cpp_rgctx_method(method->klass->rgctx_data, 11)))(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t BitConverter_DoubleToInt64Bits_m4F42741818550F9956B5FBAF88C051F4DE5B0AE6_inline (double ___0_value, const RuntimeMethod* method) 
{
	{
		int64_t L_0 = *((int64_t*)((uintptr_t)(&___0_value)));
		return L_0;
	}
}
