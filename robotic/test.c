// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "test.h"

// ======================================================================

void print_maze(MAZE * maze)
{
  // maze->map[maze->here_r][maze->here_c] = '*';
  for(int i = 0; i < MAX_MAZE_SIZE; i++){
    for(int j = 0; j < MAX_MAZE_SIZE; j++){
      printf("%c ", maze->map[i][j]);
    }
    printf("\n");
  }
  prinf("\n");
}

// ======================================================================

void push_loc(MAZE * maze, int r, int c)
{
  if(r < 0 || c < 0) return;
  if(maze->map[r][c] == '0') {
    push_stack(maze->stack, r);
    push_stack(maze->stack, c);
    print_stack(maze->stack);
  }
}

// ======================================================================

void vacuum_spin(int goto_r, int goto_c){
    // 고립되었을 때
    if((goto_r != 0) && (goto_c != 0)){

	...

    }
	
	
    if(goto_r == -1){
	// 자이로센서가 0도가 될 때까지 시계방향 회전하는 코드
	vacuum_run();  // dc모터바퀴를 한칸 이동하도록 동작시키는 코드
	return;
    }
    if(goto_r == 1){
	// 자이로센서가 180도가 될 때까지 시계방향으로 회전하는 코드
	return;
    }
    if(goto_c == -1){
	// 자이로센서가 270도가 될 때까지 시계방향으로 회전하는 코드
	return;
    }
    if(goto_c == 1){
	// 자이로센서가 90도가 될 때까지 시계방향으로 회전하는 코드
	return;
    }
    if(goto_r < -1){
	// 자이로센서가 0도가 될 때까지 시계방향 회전하는 코드
	for(int i = goto_r; i < 0; i++)
	    vacuum_run();
	return;
    }
    if(goto_r > 1){
	// 자이로센서가 180도가 될 때까지 시계방향으로 회전하는 코드
	for(int i = 0; i < goto_r; i++)
	    vacuum_run();
	return;
    }
    if(goto_c < -1){
	// 자이로센서가 270도가 될 때까지 시계방향으로 회전하는 코드
	for(int i = goto_c; i < 0; i++)
	    vacuum_run();
	return;
    }
    if(goto_c > 1){
	// 자이로센서가 90도가 될 때까지 시계방향으로 회전하는 코드
	for(int i = 0; i < goto_c; i++)
	    vacuum_run();
	return;
    }
    
}	    
	
int run_maze(MAZE * maze)
{
  int r, c;

  r = maze->here_r;  // 이동전 세로 위치
  c = maze->here_c;  // 이동전 가로 위치

  // 2. 위, 오른쪽, 왼쪽, 아래쪽 순서로 stack에 좌표를 push
  maze->map[r][c] = '2';
  push_loc(maze, r - 1, c);
  push_loc(maze, r, c + 1);
  push_loc(maze, r, c - 1);
  push_loc(maze, r + 1, c);

  // 3. stack에서 pop한 위치로 로봇청소기 이동
  if(empty_stack(maze->stack)){
    return FAILED;
  }
  else{
    maze->here_c = pop_stack(maze->stack);
    maze->here_r = pop_stack(maze->stack);

    int goto_r = (maze->here_r) - r;
    int goto_c = (maze->here_c) - c;

    vacuum_spin(goto_r, goto_c);  // 로봇청소기가 얼마큼 회전하는지 결정하는 함수(자이로센서 사용)
    // 이 함수 내부에서 vacuum_run 함수를 호출한다. vacuum_run은 앞으로 한칸 이동.


    // stack에서 pop한 위치로 이동하는 과정
    for(int i = 0; i < abs(goto_r); i++){
	if(goto_r > 0){
	    if(maze->map[(maze->here_r)+1][maze->here_c] == 1){
	        if(goto_c > 0) {
		    (maze->here_c)++;
		    Ccount++;
		}
		else {
		    (maze->here_c)--;
		    Ccount--;
		}
	    }
	    else
		(maze->here_r)++;
	}
	else{
	    if(maze->map[(maze->here_r)-1][maze->here_c] == 1){
                for(int j = 0; j < abs(goto_c); j++){
                    if(goto_c > 0)
			(maze->here_c)++;		    
                    else
			(maze->here_c)--;
                }
            }
	    else
		(maze->here_r)--;
	}
    }
    
    for(int i = 0; i < abs(goto_c); i++){  // 반복횟수 재설정필요
	if(goto_c > 0){
            if(maze->map[maze->here_r][(maze->here_c)+1] == 1){
                if(goto_r > 0) {
                    (maze->here_r)++;
                    count++;
                }
                else {
                    (maze->here_r)--;
                    count++;
                }
            }
            else
                (maze->here_c)++;
         }
         else{
             if(maze->map[(maze->here_r)-1][maze->here_c] == 1){
                 for(int j = 0; j < abs(goto_c); j++){
                     if(goto_c > 0)
                         (maze->here_c)++;
                     else
                         (maze->here_c)--;
                 }
             }
             else
                 (maze->here_r)--;
        }
    }

	
	//maze->map[maze->here_r][maze->here_c] = '2';
    }

    
    return FINDING;
  }
}

// ======================================================================
