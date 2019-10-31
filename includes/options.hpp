#pragma once

#include "toml.hpp"

class OptionsParser
{
public:
  OptionsParser(const std::string&);
  ~OptionsParser(void) {}

  // TODO: modifier le type de retour en cohérence
  // avec la structure de données renvoyée.
  void parse(void);

private:
  std::string m_file_name;
  toml::value m_data;
};
