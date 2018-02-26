import java.util.*;
class Node{
    private int nStu ;
    private int nCake;
    public Node(int nStu , int nCake ){
        this.nStu = nStu;
        this.nCake = nCake;
    }
    public int getnStu(){
        return nStu;
    }
    public int getnCake(){
        return nCake;
    }
    public void addCake(){
        nCake++;
    }
}
class CheeseCake{

public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int B = sc.nextInt();
    int[] arr  = new int[N];
    int ext = B - N ;
    MyComparator mc = new MyComparator();
    PriorityQueue<Node> queue = new PriorityQueue<>(mc);
    for(int i = 0 ; i < N ; i++){
        //arr[i] = sc.nextInt();
        int temp = sc.nextInt();
        Node newNode = new Node(temp , 1);
        queue.add(newNode);
    }
    while(ext != 0){
        Node new1 = queue.poll();
        new1.addCake();
        queue.add(new1);
        ext--;
    }
    Node newNode1 = queue.poll();
    int fStu = newNode1.getnStu();
    int fCake = newNode1.getnCake();
    System.out.println((fStu+1)/2);

}
}
class MyComparator implements Comparator<Node>{
@Override
public int compare(Node n1 , Node n2){
    /*arranging based on the students per cakes*/
    double avg1 = n1.getnStu() / n1.getnCake();
    double avg2 = n2.getnStu() / n2.getnCake();
    if(avg1 > avg2){
        return -1;
    }
    if(avg1 < avg2){
        return 1;
    }
    return 0;
}
}
