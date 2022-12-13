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
	question_find_excercise_by_specific_body_part = ctx.HelperResolveSystemIdtf("question_find_excercise_by_specific_body_part", ScType::Node); result = result && question_find_excercise_by_specific_body_part.IsValid(); \
	question_find_vitamins = ctx.HelperResolveSystemIdtf("question_find_vitamins", ScType::Node); result = result && question_find_vitamins.IsValid(); \
	question_search_diseases_with_disease_prevention = ctx.HelperResolveSystemIdtf("question_search_diseases_with_disease_prevention", ScType::Node); result = result && question_search_diseases_with_disease_prevention.IsValid(); \
	question_search_diseases_with_transmission_method = ctx.HelperResolveSystemIdtf("question_search_diseases_with_transmission_method", ScType::Node); result = result && question_search_diseases_with_transmission_method.IsValid(); \
	question_find_disease_with_organ_system = ctx.HelperResolveSystemIdtf("question_find_disease_with_organ_system", ScType::Node); result = result && question_find_disease_with_organ_system.IsValid(); \
	question_find_disease_with_symptom = ctx.HelperResolveSystemIdtf("question_find_disease_with_symptom", ScType::Node); result = result && question_find_disease_with_symptom.IsValid(); \
	nrel_calorie_content = ctx.HelperResolveSystemIdtf("nrel_calorie_content", ScType::Node); result = result && nrel_calorie_content.IsValid(); \
	nrel_protein_content = ctx.HelperResolveSystemIdtf("nrel_protein_content", ScType::Node); result = result && nrel_protein_content.IsValid(); \
	nrel_fats_content = ctx.HelperResolveSystemIdtf("nrel_fats_content", ScType::Node); result = result && nrel_fats_content.IsValid(); \
	nrel_carbohydrates_content = ctx.HelperResolveSystemIdtf("nrel_carbohydrates_content", ScType::Node); result = result && nrel_carbohydrates_content.IsValid(); \
	nrel_inclusion = ctx.HelperResolveSystemIdtf("nrel_inclusion", ScType::Node); result = result && nrel_inclusion.IsValid(); \
	nrel_is_contained_in = ctx.HelperResolveSystemIdtf("nrel_is_contained_in", ScType::Node); result = result && nrel_is_contained_in.IsValid(); \
	nrel_disease_transmission_method = ctx.HelperResolveSystemIdtf("nrel_disease_transmission_method", ScType::Node); result = result && nrel_disease_transmission_method.IsValid(); \
	nrel_disease_prevention = ctx.HelperResolveSystemIdtf("nrel_disease_prevention", ScType::Node); result = result && nrel_disease_prevention.IsValid(); \
	nrel_diseases_of_system = ctx.HelperResolveSystemIdtf("nrel_diseases_of_system", ScType::Node); result = result && nrel_diseases_of_system.IsValid(); \
	nrel_symptom = ctx.HelperResolveSystemIdtf("nrel_symptom", ScType::Node); result = result && nrel_symptom.IsValid(); \
    return result; \
}


#define keynodes_hpp_20_decl 

#define keynodes_hpp_Keynodes_impl 

#undef ScFileID
#define ScFileID keynodes_hpp

