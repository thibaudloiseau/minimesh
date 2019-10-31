#include <memory>

#include "options.hpp"

OptionsParser::OptionsParser(const std::string& file_name)
  : m_file_name(file_name)
{
  m_data = toml::parse(m_file_name);
}

void OptionsParser::parse(void)
{
  const auto transform = toml::find(m_data, "transform");
  const auto name = toml::find<std::string>(transform, "name");

  if (name.compare("merge") == 0) {
    bool merge_nodes = toml::find<bool>(transform, "merge_nodes");
    
    const auto io = toml::find(m_data, "io");
    std::vector<std::string> meshes = toml::find<std::vector<std::string>>(io, "inputs");
    std::string result_file_name = toml::find<std::string>(io, "output");

    const auto quality = toml::find(m_data, "quality");
    bool compute_quality = toml::find<bool>(quality, "compute_quality");

  } else if (name.compare("translate") == 0) {
    auto coords = toml::find<std::vector<double>>(transform, "translation");

    const auto io = toml::find(m_data, "io");
    std::string mesh = toml::find<std::string>(io, "input");
    std::string result_file_name = toml::find<std::string>(io, "output");

    const auto quality = toml::find(m_data, "quality");
    bool compute_quality = toml::find<bool>(quality, "compute_quality");

  } else {
  }
}
