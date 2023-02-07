// AUTOGRADER.CC
// Author: Trip Master
// -----------------------
// This code is the baseline implementation for a simple
// autograder. It analyzes printline output from a 
// target executable. To run the autograder, simply invoke:
//
// ./autograder ./EXEC_NAME
//
// where EXEC_NAME is the path to
// the executable you would like to invoke. The body of the code
// itself is somewhat flexible -- if you'd like to do other things
// with it, you can change the code in check_answer to do so.

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <map>
#include <fcntl.h>
#include <string>
#include <string.h>
#include <cerrno>

using namespace std;

/* Map of test strings. Do not modify. */
const map<string, string> TEST_WORDS = {
    { "hello", "olleh" },
    { "Capitalization", "noitazilatipaC" },
    { "", "" },
    { " ", " " },
    { "a", "a"},
    { "aA", "Aa"},
    { "able was i ere i saw elba", "able was i ere i saw elba"}
};
/* Global count of student points. Global is a-okay here! */
int student_points = 0; 

/**
 * check_answer()
 * --------------
 * Given the size of the student string, the student char * itself,
 * and the reference (un-reversed) string, check whether the string
 * matches the reference solution. This code actually does some hacks
 * on the side to make correct answers align with the map data, but 
 * you don't need to worry about it.
 * 
 * You specifically will need to provide check_answer() with the correct
 * data in grade_submission. HINT: there are many ways you can represent
 * the size of the string -- pick the one that is the most reliable.
*/ 
void check_answer(size_t student_sz, char *student, const string reference) {
    /* Necessary NULL-termination because of the newline in
        the executable output. Don't worry about this... */
    if (student_sz == 0) {
        *student = '\0';
    } else {
        student[student_sz] = '\0';
    }

    if (student == string(TEST_WORDS.at(reference))) {
        student_points++;
    }
}

/**
 * grade_submission
 * ----------------
 * Given a path to the executable, run the executable with each word
 * in TEST_WORDS. This will require you to run the executable once per
 * word in the map. You will then retrieve the output of the executable
 * and send it to check_answer() for verification.
*/
void grade_submission (char *executable_path) {
    for (const auto &key_value_pair : TEST_WORDS) {

        /* Silly "boilerplate" to extract the key from the map. Please ignore. */
        const char *test_word = key_value_pair.first.c_str();
        char test_word_copy[strlen(test_word) + 1];
        strcpy(test_word_copy, test_word);
        
        // TODO: Implement the autograder!

    }
}

int main (int argc, char *argv[]) {

    /* 1. Ensure that we only get 1 additional argument.*/
    if (argc != 2) {
        cout << "ERROR: Incorrect number of arguments." << endl;
        cout << "Aborting..." << endl;
    }

    /* Run our autograde routine. */
    grade_submission (argv[1]);
    
    cout << "Student passed " << student_points << " out of 7 tests." << endl;

    return 0;
}