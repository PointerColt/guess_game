#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>
#include <format>



using json = nlohmann::json;

std::string ask_gemini(std::string prompt) {
    // 1. The URL MUST have the key at the end
    std::string apiKey ="GEMINI_API_KEY"; 
    
    
    
    std::string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key=" + apiKey;

    json requestBody = {
        {"contents",json::array({
            {
                {"parts",json::array({
                {{"text",prompt}}
            })}
        }
        })}
    };

    
    cpr::Response r = cpr::Post(
        cpr::Url{url},
        cpr::Header{{"Content-Type", "application/json"}},
        cpr::Body{requestBody.dump()}
    );

    if (r.status_code == 200) {
        json responseJson =json::parse(r.text);
        return responseJson["candidates"][0]["content"]["parts"][0]["text"];
    } else {
        return "Error: " + std::to_string(r.status_code) + " - Check your key or internet.";
    }
}


std::string build_prompt(std::string animal, std::string question) {
    return std::format(
        "You are playing a game of 10 questions. The user is trying to guess "
        "your secret animal: {}. They just asked: {}. "
        "IMPORTANT: Do not mention the animal name '{}' in your response unless they guessed it. "
        "If they are correct, respond ONLY with 'You guessed it!'.", 
        animal, question, animal
    );
}



int main() {

/*    
    // Which compiler is in use
    #if defined(_MSC_VER)
        std::cout << "Built with: Microsoft Visual C++ (MSVC)" << std::endl;
    #elif defined(__GNUC__) && !defined(__clang__)
        std::cout << "Built with: GNU GCC" << std::endl;
    #elif defined(__clang__)
        std::cout << "Built with: Clang" << std::endl;
    #else
        std::cout << "Built with: Unknown Compiler" << std::endl;
    #endif
*/

/*
    // calling gemini 2.5 flash , by API
    std::cout << "Asking Gemini AI..." << std::endl;
    std::cout << "\nResponse: " << ask_gemini("distance between sun and earth") << std::endl;
    
    std::cout << "\n----------------------------" << std::endl;
    std::system("pause");   // Pause the terminal 
*/

    std::cout << "Try and Guess My animal!" << std::endl;
    std :: string animal {"lion"};
    std :: string question ;
    bool won = false ;

    for (int i {10} ; i>0 ; --i){
        std::cout << "You have " << i << " question left. Enter a question : " ;
        getline(std::cin , question);
        std :: string prompt = build_prompt(animal, question);
        std :: string answer = ask_gemini(prompt);
        std :: cout << answer << std :: endl;
        if (answer.find("You guessed it!") != std::string::npos) { 
            std::cout << "Congratulations! You win!" << std::endl;
            won = true;
            break;
        }
    }

    if (!won) {
        std::cout << "Game Over! You've run out of questions. The animal was: " << animal << std::endl;
    }


    return 0;
}


