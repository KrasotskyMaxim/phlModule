#include <memory>

#include "sc-memory/sc_memory.hpp"


#include "sc-memory/sc_event.hpp"




#define keynodes_hpp_20_init  bool _InitInternal() override \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "Keynodes::_InitInternal"); \
    bool result = true; \
    return result; \
}


#define keynodes_hpp_20_initStatic static bool _InitStaticInternal()  \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "Keynodes::_InitStaticInternal"); \
    bool result = true; \
	question_find_products_by_cpfc = ctx.HelperResolveSystemIdtf("question_find_products_by_cpfc", ScType::Node); result = result && question_find_products_by_cpfc.IsValid(); \
	nrel_calorie_content = ctx.HelperResolveSystemIdtf("nrel_calorie_content", ScType::Node); result = result && nrel_calorie_content.IsValid(); \
	nrel_protein_content = ctx.HelperResolveSystemIdtf("nrel_protein_content", ScType::Node); result = result && nrel_protein_content.IsValid(); \
	nrel_fats_content = ctx.HelperResolveSystemIdtf("nrel_fats_content", ScType::Node); result = result && nrel_fats_content.IsValid(); \
	nrel_carbohydrates_content = ctx.HelperResolveSystemIdtf("nrel_carbohydrates_content", ScType::Node); result = result && nrel_carbohydrates_content.IsValid(); \
    return result; \
}


#define keynodes_hpp_20_decl 

#define keynodes_hpp_Keynodes_impl 

#undef ScFileID
#define ScFileID keynodes_hpp

