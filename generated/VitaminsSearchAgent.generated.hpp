#include <memory>

#include "sc-memory/sc_memory.hpp"


#include "sc-memory/sc_event.hpp"




#define VitaminsSearchAgent_hpp_14_init  bool _InitInternal() override \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "VitaminsSearchAgent::_InitInternal"); \
    bool result = true; \
    return result; \
}


#define VitaminsSearchAgent_hpp_14_initStatic static bool _InitStaticInternal()  \
{ \
    ScMemoryContext ctx(sc_access_lvl_make_min, "VitaminsSearchAgent::_InitStaticInternal"); \
    bool result = true; \
    return result; \
}


#define VitaminsSearchAgent_hpp_14_decl \
private:\
	typedef ScAgent Super;\
protected: \
	VitaminsSearchAgent(char const * name, sc_uint8 accessLvl) : Super(name, accessLvl) {}\
	virtual sc_result Run(ScAddr const & listenAddr, ScAddr const & edgeAddr, ScAddr const & otherAddr) override; \
private:\
	static std::unique_ptr<ScEvent> ms_event;\
    static std::unique_ptr<ScMemoryContext> ms_context;\
public: \
	static bool handler_emit(ScAddr const & addr, ScAddr const & edgeAddr, ScAddr const & otherAddr)\
	{\
		VitaminsSearchAgent Instance("VitaminsSearchAgent", sc_access_lvl_make_min);\
		return Instance.Run(addr, edgeAddr, otherAddr) == SC_RESULT_OK;\
	}\
	static void RegisterHandler()\
	{\
		SC_ASSERT(!ms_event.get(), ());\
		SC_ASSERT(!ms_context.get(), ());\
		ms_context.reset(new ScMemoryContext(sc_access_lvl_make_min, "handler_VitaminsSearchAgent"));\
		ms_event.reset(new ScEvent(*ms_context, Keynodes::question_find_vitamins, ScEvent::Type::AddOutputEdge, &VitaminsSearchAgent::handler_emit));\
        if (ms_event.get())\
        {\
            SC_LOG_INFO("Register agent VitaminsSearchAgent");\
        }\
        else\
        {\
            SC_LOG_ERROR("Can't register agent VitaminsSearchAgent");\
        }\
	}\
	static void UnregisterHandler()\
	{\
		ms_event.reset();\
		ms_context.reset();\
	}

#define VitaminsSearchAgent_hpp_VitaminsSearchAgent_impl \
std::unique_ptr<ScEvent> VitaminsSearchAgent::ms_event;\
std::unique_ptr<ScMemoryContext> VitaminsSearchAgent::ms_context;

#undef ScFileID
#define ScFileID VitaminsSearchAgent_hpp

