import java.util.Scanner;

public class MineSweeper extends Display_Mine {
        public static void main(String[] args) {
                Scanner cin = new Scanner(System.in);
                MineSweeper obj = new MineSweeper();
                obj.displayStrblock();
                
                while (!obj.life) {
                        System.out.println("\nŽc‚è”š’e” : " + obj.mines);
                        System.out.print("À•W‚ðŽw’è ");
                        System.out.print("c [Space] ‰¡ >>");
                        obj.mineChecking(Integer.parseInt(cin.next()),Integer.parseInt(cin.next()));
                        obj.displayStrblock();
                }
        }
}

class Display_Mine {
        int mines=0;
        String[][] block_str=new String[10][10];
        int[][] blocks=new int[10][10];
        boolean life=false;
        
        public Display_Mine() {
                mineSet();
        }
        
        void mineSet() {
                for (int i=0; i<blocks.length; i++) {
                        for (int j = 0; j<blocks[i].length; j++) {
                                if (Math.random()<0.2) {
                                        blocks[i][j] = 0x0f;
                                        mines += 1;
                                } else {
                                        blocks[i][j] = 0;
                                }
                        }
                }
                for (int i=0; i<block_str.length; i++) {
                        for (int j=0; j<block_str.length; j++) {
                                block_str[i][j] = "¡";
                        }
                }
        }

        void displayStrblock() {
                for (int i=0; i<block_str.length; i++) {
                        for (int j=0; j<block_str.length; j++) {
                                if(!block_str[i][j].equals("¡"))
                                        System.out.print(" "+block_str[i][j]);
                                else
                                        System.out.print(block_str[i][j]);
                        }
                        
                System.out.println(":" + i);
                }
        }
        
        int aroundMinesCheckALL(int i, int j) {
                if (blocks[i][j] == 0x0f) {
                        return 0x0f;
                }
                int ans=0;
                
                for (int n=-1; n<=1; n++)
                        for (int m=-1; m<=1; m++) {
                                try {
                                        if (blocks[i+n][j+m]==0x0f) {
                                                ans += 1;
                                        }
                                }catch (ArrayIndexOutOfBoundsException e) {
                                        continue;
                                }
                        }
                return ans;
        }

        void mineChecking(int i, int j) {
                if (aroundMinesCheckALL(i, j) == 0x0f) {
                        System.out.println("BOMB!");
                        System.out.println("GAME OVER\n");
                        block_str[i][j] = "*";
                        life = true;
                } else {
                        block_str[i][j]=Integer.toString(aroundMinesCheckALL(i, j));
                }
        }
}

