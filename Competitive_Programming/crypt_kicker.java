import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;


/* 
* Input:
* 6 bbb aaa ddd ccc fff eee
* When we need to submit practical
* 
* Output:
* bbb aaa ddd ccc fff eee
* 
* 
* Input:
* 6 bbb aaa ddd ccc fff eee
* Do you have any idea regarding it
* 
* Output:
* Failed to map
*/

class Main {
  public static void main(String args[]) {
    // Setting up input streams
    Scanner input;
    try {
      input = new Scanner(new File("./input.txt"));
    } catch (FileNotFoundException e) {
      input = new Scanner(System.in);
    }

    // Get the words
    Integer n = input.nextInt();
    List<String> words = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      words.add(input.next());
    }

    // Get the message
    input.nextLine(); // Clear new line left over
    String target = input.nextLine().strip();
    List<String> token = Arrays.asList(target.split(" "));

    // Map the message with available words
    HashMap<String, String> map = new HashMap<>();
    boolean failed = false;
    for (String value : token) {
      if (map.containsKey(value)) {
        continue;
      } else {
        if (words.isEmpty()) {
          failed = true;
          break;
        }
        String random_word = words.get(0);
        map.put(value, random_word);
        words.remove(0);
      }
    }

    // If insufficient keywords, failed
    if (failed == true){
      System.out.println("Failed to map");
      return;
    }

    // Build the encrypted string
    StringBuilder outString = new StringBuilder();
    for (String value : token) {
      outString.append(" " + map.get(value));
    }

    // Prompt the output
    System.out.println("Input: " + target);
    System.out.println("Output: " + outString.toString().strip());
  }
}