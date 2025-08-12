import java.util.*;

public class CollectionFrameworkDemo {
    public static void main(String[] args) {
        // Using ArrayList to store and display a list of names
        List<String> names = new ArrayList<>();
        names.add("Alice");
        names.add("Bob");
        names.add("Charlie");
        System.out.println("Names: " + names);

        // Using HashSet to store unique elements
        Set<Integer> uniqueNumbers = new HashSet<>();
        uniqueNumbers.add(10);
        uniqueNumbers.add(20);
        uniqueNumbers.add(10); // Duplicate, will not be added
        System.out.println("Unique Numbers: " + uniqueNumbers);

        // Using HashMap to store key-value pairs
        Map<String, Integer> ageMap = new HashMap<>();
        ageMap.put("Alice", 25);
        ageMap.put("Bob", 30);
        ageMap.put("Charlie", 22);
        System.out.println("Ages: " + ageMap);

        // Iterating over a collection
        System.out.println("Iterating over names:");
        for (String name : names) {
            System.out.println(name);
        }
    }
}
