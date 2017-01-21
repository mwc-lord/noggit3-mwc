// This file is part of Noggit3, licensed under GNU General Public License (version 3).

#include <noggit/Project.h>

#include <string>
#include <boost/filesystem.hpp>

#include <noggit/ConfigFile.h>

Project::Project()
{
  // Read out config and set path in project if exists.
  // will later come direct from the project file.
  if (boost::filesystem::exists("noggit.conf"))
  {
    ConfigFile config("noggit.conf");
    if (config.keyExists("ProjectPath"))
      config.readInto(path, "ProjectPath");
  }
  // else set the project path to the wow std path


}

Project* Project::instance = 0;


Project* Project::getInstance()
{
  if (!instance)
    instance = new Project();
  return instance;
}

void Project::setPath(const std::string& _setPath)
{
  path = _setPath;
}

std::string Project::getPath()
{
  return path;
}