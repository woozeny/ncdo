#ifndef NCDO_CONFIG_H
#define NCDO_CONFIG_H

#include <string>

using namespace std;

namespace cdo {
class config {
 public:
  config() : config("") {};
  explicit config(const string &conf_path = "");
  config(const config &o) = default;
  config(config &&) = default;
  ~config() = default;

  config &operator=(const config &) = default;

  // ---
  // Extra methods
  // ---

  void singleFileSetup(const string &path) {
    todo_dir = "";
    todo_file = path;
    done_file = path;
    single_file = true;
    report_enabled = false;
    create_if_not_exists = true;
  }

  // ---
  // Getters for config properties
  // ---

  string getTodoFile() { return resolve(todo_dir, todo_file); }
  string getDoneFile() { return single_file ? resolve(todo_dir, todo_file) : resolve(todo_dir, done_file); }
  string getReportFile() { return resolve(todo_dir, report_file); }

  bool isReportEnabled() { return report_enabled; }
  bool createIfNotExists() { return create_if_not_exists; }

 protected:
  string resolve(string base, string other = "");

 private:
  string todo_dir = "~/.todo";
  string todo_file = "todo.txt";
  string done_file = "done.txt";
  string report_file = "report.txt";
  bool single_file = false;
  bool report_enabled = true;
  bool create_if_not_exists = false;
};
}

#endif //NCDO_CONFIG_H
