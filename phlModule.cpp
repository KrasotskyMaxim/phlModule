/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#include "phlModule.hpp"
#include "keynodes/keynodes.hpp"
#include "agents/FindProductsByCPFCAgent.hpp"

using namespace phlModule;

SC_IMPLEMENT_MODULE(PHLModule)

sc_result PHLModule::InitializeImpl()
{
  if (!phlModule::Keynodes::InitGlobal())
    return SC_RESULT_ERROR;

  SC_AGENT_REGISTER(FindProductsByCPFCAgent)

  return SC_RESULT_OK;
}

sc_result PHLModule::ShutdownImpl()
{
  SC_AGENT_UNREGISTER(FindProductsByCPFCAgent)

  return SC_RESULT_OK;
}
