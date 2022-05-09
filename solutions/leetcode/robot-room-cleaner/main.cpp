/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the
 * cell.
 *     // Returns false if the cell in front is blocked and robot stays in the
 * current cell. bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

   public:
    void cleanRoom(Robot& robot) {
        auto go_back = [&]() -> void {
            robot.turnLeft();
            robot.turnLeft();
            robot.move();
            robot.turnLeft();
            robot.turnLeft();
        };

        unordered_map<int, unordered_set<int>> vis;
        function<void(int, int, int)> dfs = [&](int i, int j, int d) -> void {
            vis[i].insert(j);
            robot.clean();

            for (int k = 0; k < 4; ++k) {
                robot.turnLeft();
                d = (d + 1) % 4;
                int ii = i + directions[d][0];
                int jj = j + directions[d][1];

                if (vis[ii].count(jj) || !robot.move()) continue;

                dfs(ii, jj, d);

                go_back();
            }
        };

        dfs(0, 0, 0);
    }
};
