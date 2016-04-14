/**
 * int 异或碰撞
 */
import java.util.Scanner;

public class IntXOR{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int m = s.nextInt();
        int n = s.nextInt();
        System.out.println(hashCode(m)^hashCode(n));//就是n本省
        System.out.println(Double.doubleToLongBits(n));
    }

    public static int hashCode(int n){
        return Integer.hashCode(n);
    }
}
