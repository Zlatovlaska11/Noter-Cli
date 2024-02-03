#include "string"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iterator>
#include <ostream>
#include <string>

class Noter {
public:
  void WriteNote(std::string text, std::string path) {
    FILE *file;
    const char *PathChar = path.c_str();
    const char *TextChar = text.c_str();
    file = std::fopen(PathChar, "a");

    std::fputs("_", file);
    std::fputs(TextChar, file);
    std::fputs("_", file);
    std::fputc('\n', file);
    std::fclose(file);
  }

  void DisplayNotes(std::string path) {
    std::string command = "glow" + path;
    system("cat text.txt"); // replace with glow file.md command for good
                            // markdown displaying
  }
};

int main(int argc, char *argv[]) {

  // std::cout << argv[2]; // used to get argument while calling the file
  Noter note;
  if (strcmp(argv[1], "-d") == 0) {
    // Display mode to display notes
    note.DisplayNotes(argv[3]);

  } else if (strcmp(argv[1], "-wi") == 0) {

    note.WriteNote(argv[2], argv[3]);
  }

  return 0;
}
