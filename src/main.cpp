#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <tuple>

#include "cxxopts.hpp"

#include "options.hpp"

const std::pair<std::string, std::string> parse(int argc, char **argv)
{
  try {
    cxxopts::Options options("minimesh",
      "A VTK-focused unstructured mesh manipulation mini-app");
    
    options
      .positional_help("[optional args]")
      .show_positional_help();

    options.add_options()
      ("v,view", "View a mesh", cxxopts::value<std::string>(), "Mesh file")
      ("t,transform", "Transform (merge, translate) a mesh", cxxopts::value<std::string>(), "Transform file")
      ("h,help", "Print help");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
      std::cout << options.help({""}) << "\n";
      std::exit(0);
    }

    if (result.count("transform")) {
      return std::make_pair("transform", result["transform"].as<std::string>());
    }

    if (result.count("view")) {
      return std::make_pair("view", result["view"].as<std::string>());
    }

    return std::make_pair("", "");

  } catch (const cxxopts::OptionException& e) {
    std::cout << "Error parsing options: " << e.what() << "\n";
    std::exit(1);
  }
}

int main(int argc, char **argv)
{
  std::string command;
  std::string file_name;
  std::tie(command, file_name) = parse(argc, argv);

  if (command.compare("transform") == 0) {
    auto op = std::make_unique<OptionsParser>(file_name);
    auto params = op->parse();

  } else if (command.compare("view") == 0) {

  }
 
  return EXIT_SUCCESS;
}
