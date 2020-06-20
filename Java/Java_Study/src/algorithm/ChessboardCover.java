package algorithm;

import java.util.Scanner;

/*
***分治法解决棋盘覆盖问题
 */
/**
 * Created by Optimist in 2020/3/10
 */
public class ChessboardCover {

    private static int row=1;
    private static int[][] ch = new int[1030][1030];
    private static int now = 1;//骨牌编号


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        x++;
        y++;
        ch[x][y] = 0;
        for(int i = 1; i<= k; i++)
            row *= 2;
        divide(1,1,row, x, y);
        for (int i=1;i<=row;i++){
            for (int j=1;j<=row;j++)
                System.out.print(ch[i][j] + "\t");
            System.out.print("\n");
        }
    }

    private static void divide(int zx, int zy, int si, int x, int y){
        if (si == 1)
            return;
        int mx,my,mid;
        mid = si / 2;
        mx = zx + si / 2 - 1;
        my = zy + si / 2 - 1;
        if (x > mx && y > my)
        {
            ch[mx][my] = ch[mx+1][my] = ch[mx][my+1] = now;
            now++;
            divide(zx,zy,mid,zx+mid-1,zy+mid-1);
            divide(zx,zy+mid,mid,zx+mid-1,zy+mid);
            divide(zx+mid,zy,mid,zx+mid,zy+mid-1);
            divide(zx+mid,zy+mid,mid,x,y);
        }
        if (x>mx && y<=my)
        {
            ch[mx][my] = ch[mx][my+1] = ch[mx+1][my+1] = now;
            now++;
            divide(zx,zy,mid,zx+mid-1,zy+mid-1);
            divide(zx,zy+mid,mid,zx+mid-1,zy+mid);
            divide(zx+mid, zy,mid,x,y);
            divide(zx+mid,zy+mid,mid,zx+mid,zy+mid);
        }
        if (x<=mx && y>my){
            ch[mx][my] = ch[mx+1][my] = ch[mx+1][my+1] = now;
            now++;
            divide(zx,zy,mid,zx+mid-1,zy+mid-1);
            divide(zx,zy+mid,mid,x,y);
            divide(zx+mid,zy,mid,zx+mid,zy+mid-1);
            divide(zx+mid,zy+mid,mid,zx+mid,zy+mid);
        }
        if (x<=mx && y<=my){
            ch[mx+1][my+1] = ch[mx+1][my] = ch[mx][my+1] = now;
            now++;
            divide(zx,zy,mid,x,y);
            divide(zx,zy+mid,mid,zx+mid-1,zy+mid);
            divide(zx+mid,zy,mid,zx+mid,zy+mid-1);
            divide(zx+mid,zy+mid,mid,zx+mid,zy+mid);
        }
    }


}
