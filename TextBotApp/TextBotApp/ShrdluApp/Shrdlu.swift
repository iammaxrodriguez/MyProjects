//
//  Shrdlu.swift
//  ShrdluApp
//
//  Created by Maxwell Rodriguez on 2/22/22.
//

import Foundation

class Shrdlu {
    
    var activated = 0
    
    var inputStrings: [String] = []
    var outputStrings: [String] = []

    
    let joyWords: [String] = ["happy", "happiness", "joy", "yay", "yeah"]
    
    let disgustWords: [String] = ["gross", "disgusting", "dirty", "filthy", "ew"]
    
    let fearWords: [String] = ["scared", "worried", "scary", "alone", "ghost"]
    
    let angerWords: [String] = ["mad", "angry", "pissed", "temper", "fight"]
    
    let sadnessWords: [String] = ["upset", "sad", "dead", "passed", "crying"]
    
    
    func parseTheInput(userText: String) -> [String] {
        // first convert all letters in string to lowercase:
        let InputLowerCase = userText.lowercased()
        // then remove the "new line" at the end:
        let InputWithoutNewline = InputLowerCase.components(separatedBy: "\n")
        // then take all the text that found before the "new line",
        //    and use the " " space character to split it into words:
        let InputWords = InputWithoutNewline[0].components(separatedBy: " ")
        // return all found words placed in an array of strings:
        return InputWords
    }
    
    func oneInteraction(userLine: String) -> String {
        let indiviualWords = parseTheInput(userText: userLine)
        
        var returnedString = ""
        
        // simple for loop that changes the returned string value if one of the  arrays contains the same word as user input
        for word in indiviualWords {
            if joyWords.contains(word){
                returnedString = "That is good."
            }
            else if disgustWords.contains(word){
                returnedString = "That is pretty gross."
            }
            else if fearWords.contains(word){
                returnedString = "Do not be scared."
            }
            else if angerWords.contains(word){
                returnedString = "You must change the anger into love."
            }
            else if sadnessWords.contains(word){
                returnedString = "I am here to listen"
            }
            else {
                returnedString = "Come, Come, elucidate your thoughts."
            }
        }
        // My two string arrays adding the user input and output in their seperate arrays to store.
        inputStrings.append(userLine)
        
        outputStrings.append(returnedString)
        
        return returnedString
    }
  
    // My two getter methods that return the input and output arrays.
    func getInputStrings(number: Int) -> String{
        return inputStrings[number]
        
    }
    func getOutputStrings(number: Int) -> String {
        return outputStrings[number]
    }
}
