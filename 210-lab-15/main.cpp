#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Movie {
private:
    string title;
    int yearReleased;
    string screenWriter;

public:
    // Setters
    void setTitle(const string& t) { title = t; }
    void setYearReleased(int y) { yearReleased = y; }
    void setScreenWriter(const string& sw) { screenWriter = sw; }

    // Getters
    string getTitle() const { return title; }
    int getYearReleased() const { return yearReleased; }
    string getScreenWriter() const { return screenWriter; }

    // Print method
    void print() const {
        cout << "Movie: " << title << endl;
        cout << "    Year released: " << yearReleased << endl;
        cout << "    Screenwriter: " << screenWriter << endl;
    }
};

int main() {
    ifstream inputFile("input.txt");
    vector<Movie> movieContainer;

    if (inputFile.is_open()) {
        string title, screenWriter;
        int yearReleased;

        while (getline(inputFile, title)) {
            inputFile >> yearReleased;
            inputFile.ignore(); // ignore the newline character
            getline(inputFile, screenWriter);

            Movie tempMovie;
            tempMovie.setTitle(title);
            tempMovie.setYearReleased(yearReleased);
            tempMovie.setScreenWriter(screenWriter);
            movieContainer.push_back(tempMovie);
        }

        inputFile.close();
    }
    else {
        cerr << "Unable to open input file." << endl;
        return 1;
    }

    // Output the contents of the container
    for (const auto& movie : movieContainer) {
        movie.print();
        cout << endl;
    }

    return 0;
}