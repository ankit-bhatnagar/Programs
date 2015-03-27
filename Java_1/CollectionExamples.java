import java.util.*;

public class CollectionExamples {

	public static void linkedListExample() {
		LinkedList<String> list1 = new LinkedList<String>();
		list1.add("Hello");
		list1.add("Sir");
		list1.add("How");
		list1.add("Do");
		list1.add("You");
		list1.add("Do");
		System.out.println("Linked List Content: " +list1);

		list1.add(2, "Deepak");
		list1.set(2, "Deepak Rawat");

		/* Nice way, using for loop */
		for (String s:list1) {
			System.out.println(s);
		}

		System.out.println("===============Iterator===================");
		/* Using iterator */
		Iterator iter = list1.iterator();
		while (iter.hasNext()) {
			System.out.println(iter.next());
		}

		System.out.println("===============Sort===================");
		Collections.sort(list1);
		System.out.println("Linked List Content: " +list1);
	}

	public static void arrayListExample() {
		ArrayList<String> list1 = new ArrayList<String>();
		list1.add("Hello");
		list1.add("Sir");
		list1.add("How");
		list1.add("Do");
		list1.add("You");
		list1.add("Do");
		System.out.println("Array List Content: " +list1);

		list1.add(2, "Deepak");
		list1.set(2, "Deepak Rawat");

		/* Nice way, using for loop */
		for (String s:list1) {
			System.out.println(s);
		}
	}

	public static void hashSetExample() {
		HashSet<String> list1 = new HashSet<String>();
		list1.add("Hello");
		list1.add("Sir");
		list1.add("How");
		list1.add("Do");
		list1.add("You");
		list1.add("Do");
		System.out.println("Hash Set Content: " +list1);

		/* Nice way, using for loop */
		for (String s:list1) {
			System.out.println(s);
		}
	}

	public static void hashMapExample() {
		HashMap<String, Integer> hmap = new HashMap<String, Integer>();
		hmap.put("Deepak", 63);
		hmap.put("TusharA", 85);
		hmap.put("TusharG", 70);
		hmap.put("Ritesh", 60);

		Set set = hmap.entrySet();
		Iterator iterator = set.iterator();
		while(iterator.hasNext()) {
			Map.Entry mentry = (Map.Entry)iterator.next();
			System.out.print("key is: "+ mentry.getKey() + " & Value is: ");
			System.out.println(mentry.getValue());
		}
	}

	public static void main(String []args) {
		linkedListExample();
		arrayListExample();
		hashSetExample();
		hashMapExample();
	}
}