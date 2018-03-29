#include "ExecParser.hpp"

bool check_extension(std::string filename, std::string extension) {
  int i = filename.size() - 1;
  while (i != -1) {
    if (filename[i] == '.') {
      // std::cout << filename.substr(i+1, filename.size()-i-2) << std::endl;
      return (filename.substr(i + 1, filename.size() - i - 1) == extension);
    }
    i--;
  }
  return false;
}

std::string relativePath(std::string file) {
  return file.substr(file.find_last_of("/") + 1);
}

ExecParser::ExecParser(std::string filein, std::string fileout)
    : _filein(filein), _fileout(fileout) {

  // PARSES A CONFIG FILE WITH FILE NAMES AND FUNCTIONS TO USE
  // IF THERE ARE TOO MANY OCCURENCIES OF EACH ELEMENT (ex: 2 lines with COLOR),
  // THE LAST LINE IS KEPT

  std::ifstream ifs(filein, std::ifstream::in);
  std::ofstream out;
  out.open(fileout);
  std::string line;
  std::string word;
  while (ifs) {
    getline(ifs, line);

    std::string lineout = line;
    if (line.find("FILE ") == 0) {
      std::string word = get_word(line);
      if (check_extension(word, "wav") && access(word.c_str(), F_OK) != -1) {
        tracks.push_back(word);
        lineout =
            std::string("FILE ") + std::string(WAVPATH) + relativePath(word);
      }
    }
    out << lineout << std::endl;
  }
  ifs.close();
  out.close();
}

std::string ExecParser::get_word(std::string line) {
  std::string::iterator it = line.begin();
  get_next_word(&it);
  get_next(&it);
  while (*it == ' ') {
    it++;
  }
  return get_next_word(&it);
}
std::list<std::string> ExecParser::getTracks() { return tracks; }
