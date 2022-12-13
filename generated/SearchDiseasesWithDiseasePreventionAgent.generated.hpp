#include <memory>

#include "sc-memory/sc_memory.hpp"


#include "sc-memory/sc_event.hpp"




#define SearchDiseasesWithDiseasePreventionAgent_hpp_14_init  bool _InitInternal() override \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "SearchDiseasesWithDiseasePreventionAgent::_InitInternal"); \
    bool result = true; \
    return result; \
}


#define SearchDiseasesWithDiseasePreventionAgent_hpp_14_initStatic static bool _InitStaticInternal()  \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "SearchDiseasesWithDiseasePreventionAgent::_InitStaticInternal"); \
    bool result = true; \
    return result; \
}


#define SearchDiseasesWithDiseasePreventionAgent_hpp_14_decl \
private:\
	typedef ScAgent Super;\
protected: \
	SearchDiseasesWithDiseasePreventionAgent(char const * name, sc_uint8 accessLvl) : Super(name, accessLvl) {}\
	virtual sc_result Run(ScAddr const & listenAddr, ScAddr const & edgeAddr, ScAddr const & otherAddr) override; \
private:\
	static std::unique_ptr<ScEvent> ms_event;\
    static std::unique_ptr<ScMemoryContext> ms_context;\
public: \
	static bool handler_emit(ScAddr const & addr, ScAddr const & edgeAddr, ScAddr const & otherAddr)\
	{\
		SearchDiseasesWithDiseasePreventionAgent Instance("SearchDiseasesWithDiseasePreventionAgent", sc_access_lvl_make_min);\
		return Instance.Run(addr, edgeAddr, otherAddr) == SC_RESULT_OK;\
	}\
	static void RegisterHandler()\
	{\
		SC_ASSERT(!ms_event.get(), ());\
		SC_ASSERT(!ms_context.get(), ());\
		ms_context.reset(new ScMemoryContext(sc_access_lvl_make_min, "handler_SearchDiseasesWithDiseasePreventionAgent"));\
		ms_event.reset(new ScEvent(*ms_context, Keynodes::question_search_diseases_with_disease_prevention, ScEvent::Type::AddOutputEdge, &SearchDiseasesWithDiseasePreventionAgent::handler_emit));\
        if (ms_event.get())\
        {\
            SC_LOG_INFO("Register agent SearchDiseasesWithDiseasePreventionAgent");\
        }\
        else\
        {\
            SC_LOG_ERROR("Can't register agent SearchDiseasesWithDiseasePreventionAgent");\
        }\
	}\
	static void UnregisterHandler()\
	{\
		ms_event.reset();\
		ms_context.reset();\
	}

#define SearchDiseasesWithDiseasePreventionAgent_hpp_SearchDiseasesWithDiseasePreventionAgent_impl \
std::unique_ptr<ScEvent> SearchDiseasesWithDiseasePreventionAgent::ms_event;\
std::unique_ptr<ScMemoryContext> SearchDiseasesWithDiseasePreventionAgent::ms_context;

#undef ScFileID
#define ScFileID SearchDiseasesWithDiseasePreventionAgent_hpp

