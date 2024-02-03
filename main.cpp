#include "string"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

class Noter {
public:
  void WriteNote(std::string text) {
    FILE *file;
    const char *TextChar = text.c_str();
    file = std::fopen("notes.md", "a"); // replace text.txt with note.md

    std::fputs("_", file);
    std::fputs(TextChar, file);
    std::fputs("_", file);
    std::fputc('\n', file);
    std::fclose(file);
  }

  void DisplayNotes() {
    std::string comand = "glow notes.md";

    const char *comm = comand.c_str();

    system(comm); // replace with glow file.md command for good
                  // markdown displaying
  }
};

int main(int argc, char *argv[]) {

  // std::cout << argv[2]; // used to get argument while calling the file
  std::string text = "";

  for (int i = 2; i < argc; i++) {
    text += argv[i];
    if (i != argc - 1) {
      text += " ";
    }
  }

  Noter note;
  if (strcmp(argv[1], "-d") == 0) { // Display mode to display notes
    note.DisplayNotes();

  } else if (strcmp(argv[1], "-w") == 0) { // write
    note.WriteNote(text);
  }

  return 0;
}
