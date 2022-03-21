//
//  ViewController.swift
//  ShrdluApp
//
//  Created by Maxwell Rodriguez on 2/22/22.
//
import UIKit

class InteractionViewController: UIViewController {
    // reference to our appDelegate:
    var appDelegate: AppDelegate?
    // reference to our data model:
    var myShrdlu : Shrdlu?

    
    @IBOutlet weak var labelShrdlu: UILabel!
    
    @IBOutlet weak var viewInput: UITextView!
    
    @IBOutlet weak var userInput: UITextField!
    
    
    
    @IBAction func sendInput(_ sender: Any) {
        // obtain a reference to the AppDelegate:
        self.appDelegate = UIApplication.shared.delegate as? AppDelegate

        // from the AppDelegate, obtain a reference to the Model data:
        self.myShrdlu = self.appDelegate?.myShrdlu
        
        if let unwrappedInput = userInput.text {
            viewInput.text = viewInput.text + "> " + unwrappedInput + "\n" + "Shrdlu: " + self.myShrdlu!.oneInteraction(userLine: unwrappedInput) + "\n"
        }
        userInput.text = ""
        self.myShrdlu!.activated += 1
        // gets rid of keyboard when user sends input
        userInput.resignFirstResponder()
        viewWillAppear(true)
    }
    
    //The function professor told us to implement to refresh history
    override func viewWillAppear(_ animated: Bool) {
        if let lMyTableView = self.view as? UITableView {
            lMyTableView.reloadData()
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    


}
