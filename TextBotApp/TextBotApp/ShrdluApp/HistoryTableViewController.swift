//
//  HistoryTableViewController.swift
//  ShrdluApp
//
//  Created by Maxwell Rodriguez on 2/22/22.
//
import UIKit

class HistoryTableViewController: UITableViewController {
    
    var counter = 0;
    // reference to our appDelegate:
    var appDelegate: AppDelegate?
    // reference to our data model:
    var myShrdlu : Shrdlu?
    

    override func viewDidLoad() {
        super.viewDidLoad()
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "historyCell")
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // obtain a reference to the AppDelegate:
        self.appDelegate = UIApplication.shared.delegate as? AppDelegate

        // from the AppDelegate, obtain a reference to the Model data:
        self.myShrdlu = self.appDelegate?.myShrdlu
        
        // #warning Incomplete implementation, return the number of rows
        return self.myShrdlu!.activated
    }

    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // obtain a reference to the AppDelegate:
        self.appDelegate = UIApplication.shared.delegate as? AppDelegate

        // from the AppDelegate, obtain a reference to the Model data:
        self.myShrdlu = self.appDelegate?.myShrdlu
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "historyCell", for: indexPath)
        
        cell.textLabel?.text = "You: " + self.myShrdlu!.getInputStrings(number: counter) + ", Shrdlu: " + self.myShrdlu!.getOutputStrings(number: counter)
        counter+=1
        return cell
    }
}
