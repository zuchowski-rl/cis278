#pragma once

#include "ToolRecord.h"
#include <fstream>
#include <string>

// class that manages the hardware inventory file
class Database {
  private:
    std::string file_name;

    std::fstream file;

  public:
    Database(const std::string &file_name);

    void initialize_file();
    void seed_initial_records();
    void list_records();
    void update_record();
    void delete_record();
};
