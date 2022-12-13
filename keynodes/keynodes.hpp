/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#pragma once

#include <sc-memory/sc_object.hpp>
#include <sc-memory/sc_addr.hpp>

#include "keynodes.generated.hpp"

namespace phlModule
{

class Keynodes : public ScObject
{
  SC_CLASS()
  SC_GENERATED_BODY()

public:

  SC_PROPERTY(Keynode("question_find_products_by_cpfc"), ForceCreate)
  static ScAddr question_find_products_by_cpfc;
  
  SC_PROPERTY(Keynode("question_find_excercise_by_specific_body_part"), ForceCreate)
  static ScAddr question_find_excercise_by_specific_body_part;
  
  SC_PROPERTY(Keynode("question_find_vitamins"), ForceCreate)
  static ScAddr question_find_vitamins;
  
  SC_PROPERTY(Keynode("question_search_diseases_with_disease_prevention"), ForceCreate)
  static ScAddr question_search_diseases_with_disease_prevention;
  
  SC_PROPERTY(Keynode("question_search_diseases_with_transmission_method"), ForceCreate)
  static ScAddr question_search_diseases_with_transmission_method;
  
  SC_PROPERTY(Keynode("question_find_disease_with_organ_system"), ForceCreate)
  static ScAddr question_find_disease_with_organ_system;
  
  SC_PROPERTY(Keynode("question_find_disease_with_symptom"), ForceCreate)
  static ScAddr question_find_disease_with_symptom;
  
  SC_PROPERTY(Keynode("nrel_calorie_content"), ForceCreate)
  static ScAddr nrel_calorie_content;
  
  SC_PROPERTY(Keynode("nrel_protein_content"), ForceCreate)
  static ScAddr nrel_protein_content;
  
  SC_PROPERTY(Keynode("nrel_fats_content"), ForceCreate)
  static ScAddr nrel_fats_content;
  
  SC_PROPERTY(Keynode("nrel_carbohydrates_content"), ForceCreate)
  static ScAddr nrel_carbohydrates_content;
  
  SC_PROPERTY(Keynode("nrel_inclusion"), ForceCreate)
  static ScAddr nrel_inclusion;
  
  SC_PROPERTY(Keynode("nrel_is_contained_in"), ForceCreate)
  static ScAddr nrel_is_contained_in;
  
  SC_PROPERTY(Keynode("nrel_disease_transmission_method"), ForceCreate)
  static ScAddr nrel_disease_transmission_method;
  
  SC_PROPERTY(Keynode("nrel_disease_prevention"), ForceCreate)
  static ScAddr nrel_disease_prevention;
  
  SC_PROPERTY(Keynode("nrel_diseases_of_system"), ForceCreate)
  static ScAddr nrel_diseases_of_system;
  
  SC_PROPERTY(Keynode("nrel_symptom"), ForceCreate)
  static ScAddr nrel_symptom;
  
};

} // namespace phlModule
