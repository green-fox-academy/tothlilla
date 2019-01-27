// I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
// Please fix it for me!
// Expected output: In a galaxy far far away

#include <iostream>
#include <string>

int main(int argc, char *args[]) {
    std::string example("In a dishwasher far far away"); //the original sentence.
    std::string need_word = "dishwasher"; //the word we want to change

    int start_replace = example.find(
            need_word); //Finding the index of changing word in the sentence, it should be integer.

    example.replace(start_replace, need_word.length(), "galaxy"); //Usage of replace function with a string
    // necessary parameters: index of replacing word, and its length the next one; finished by the new string.

    std::cout << example << std::endl;
    return 0;
}




/* MINTAPÉLDA
#include <iostream>

int main() {

    std::string sentence = "I like my cat";
    std::string from = "cat";

    int start_pos = sentence.find(from);

    if(start_pos == std::string::npos) { //does the sentence contain cat?
        std::cout << "Cannot replace" << std::endl;
    } else {
        sentence.replace(start_pos, from.length(), "dog");
    }
    std::cout << sentence << std::endl;

    return 0;
}
 */

/*#include <iostream>
#include <string>

int main(){
    std::string str("The quick brown fox jumps over the lazy dog."); //a "T" a 0 indexű elem

    str.replace(10, 5, "red"); // (5)

    str.replace(str.begin(), str.begin() + 3, 1, 'A'); // (6)

    std::cout << str << '\n';
    return 0;
}

// OUTPUT : A quick red fox jumps over the lazy dog.
*/

