int leo_record[19][19]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
int leo_reverse[19][19]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
int leo_counter=0;

int leo_search_oct(int leo_temp[19][19],int m,int n)
{
    int leo_case = 10*(10*(10*(10*(10*(10*(10*leo_temp[m-1][n-1]+leo_temp[m-1][n])+leo_temp[m-1][n+1])+leo_temp[m][n-1])+leo_temp[m][n+1])+leo_temp[m+1][n-1])+leo_temp[m+1][n])+leo_temp[m+1][n+1];
    return leo_case;
}

int leo_ran()
{
    return 10019-leo_counter*100-leo_counter;
}
int player(int board[19][19])
{
	int m=0,n=0,i,j;
    int guess[19][19]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

    for(i=0;i<19;i++)
    {
        for(j=0;j<19;j++)
        {
                if((board[i][j]-0)!=0)
                {
                    if(board[i][j]%2==1)
                    {
                        leo_record[i][j]=1;
                        leo_reverse[18-i][18-j]=1;
                    }
                    else
                    {
                        leo_record[i][j]=2;
                        leo_reverse[18-i][18-j]=2;

                    }
                }
        }
    }

    if(leo_counter==0)
    {
        leo_counter++;
        int leo_judge = leo_search_oct(leo_record,10,10);
        if(leo_judge==0)
            return 1010;
    }
    else if(leo_counter==1)
    {
        int leo_judge = leo_search_oct(leo_record,10,10);
        leo_counter++;
        if(leo_judge==20000000)
            return 1109;
        else
        {
            int _k = leo_ran();
            return _k;
        }
    }
    else if(leo_counter==2)
    {
        int leo_judge = leo_search_oct(leo_record,10,10);
        leo_counter++;
        if(leo_judge==20200100)
            return 1108;
        else
        {
            int _k = leo_ran();
            return _k;
        }
    }
    else if(leo_counter==3)
    {
        /*leo_search_oct(leo_record,10,10);

        leo_counter++;
        return 1008;*/

        int leo_judge = leo_search_oct(leo_record,10,10);
        leo_counter++;
        //cout << "flag" << leo_judge <<endl;
        if(leo_judge==20200120)
            return 1008;
        else
        {
            int _k = leo_ran();
            return _k;
        }
    }
    else if(leo_counter==4)
    {
        /*leo_search_oct(leo_record,10,10);

        leo_counter++;
        return 1007;*/
        int leo_judge = leo_search_oct(leo_record,10,10);
        leo_counter++;
        //cout << "flag" << leo_judge <<endl;
        if(leo_judge==20200120)
            return 1007;
        else
        {
            int _k = leo_ran();
            return _k;
        }
    }
    else if(leo_counter==5)
    {
        /*leo_search_oct(leo_record,10,10);

        leo_counter++;
        return 907;*/
        int leo_judge = leo_search_oct(leo_record,10,9);
        leo_counter++;
        //cout << "flag" << leo_judge <<endl;
        if(leo_judge==2011112)
            return 907;
        else
        {
            int _k = leo_ran();
            return _k;
        }
    }
    else if(leo_counter==6)
    {
        int leo_judge = leo_search_oct(leo_record,10,8);
        leo_counter++;
        //cout << "flag" << leo_judge <<endl;
        if(leo_judge==10212211)
            return 906;
        else
        {
            int _k = leo_ran();
            return _k;
        }
    }
    else if(leo_counter==7)
    {
        int leo_judge = leo_search_oct(leo_record,10,8);
        leo_counter++;
        //cout << "flag" << leo_judge <<endl;
        if(leo_judge==10212211)
            return 210;
        else
        {
            int _k = leo_ran();
            return _k;
        }
    }
    else if(leo_counter==8)
    {
        int leo_judge = leo_search_oct(leo_record,11,8);
        leo_counter++;
        //cout << "flag" << leo_judge <<endl;
        if(leo_judge==11221020)
            return 807;
        else
        {
            int _k = leo_ran();
            return _k;
        }
    }
    else if(leo_counter==9)
    {
        int leo_judge = leo_search_oct(leo_record,11,8);
        leo_counter++;
        if(leo_judge==11221022)
            return 1005;
        else
        {
            int _k = leo_ran();
            return _k;
        }
    }
    else if(leo_counter==10)
    {
        int leo_judge = leo_search_oct(leo_record,11,8);
        leo_counter++;
        if(leo_judge==11221022)
            return 1104;
        else
        {
            int _k = leo_ran();
            return _k;
        }
    }
    else if(leo_counter==11)
    {
        leo_search_oct(leo_record,10,10);
        leo_counter++;
        return 1203;
    }
     else
    {

        int start_pose_x=0;
        int start_pose_y=0;
        int end_pose_x=0;
        int end_pose_y=0;


        for(i=0;i<19;i++)
        {
            for(j=0;j<19;j++)
            {
                if(leo_record[i][j]!=0)
                {
                    start_pose_x=i;
                    start_pose_y=j;
                }
                if(leo_reverse[i][j]!=0)
                {
                     end_pose_x=18-i;
                     end_pose_y=18-j;
                }
            }
        }
        int temp[20][20];
        for(i=0;i<=end_pose_x-start_pose_x;i++)
        {
            for(j=0;j<=end_pose_y-start_pose_y;j++)
            {
                temp[i][j] = board[i+start_pose_x][j+start_pose_y];
            }
        }


        for(i=0;i<=end_pose_x-start_pose_x;i++)
        {
            for(j=0;j<=end_pose_y-start_pose_y;j++)
            {
                if (temp[i][j]==0)
                {
                    m = i+start_pose_x;
                    n = j+start_pose_y;
                }
            }
        }


        cout<< board - guess << "error"<<endl;
        return m*100+n;
    }
}
