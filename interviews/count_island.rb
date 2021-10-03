# Counting Island
# Similar question with the following: https://leetcode.com/problems/number-of-islands/
# Part of a coding interview


grid = [
  ["0","0","0","1","0"],
  ["1","1","0","1","0"],
  ["0","1","0","0","0"],
  ["0","0","0","0","0"]
]

is_visited = Array.new(grid.length()) {Array.new(grid[0].length()) {false}}

island_count = 0
(0...(grid.length())).each do |x|
  (0...(grid[x].length())).each do |y|
    if grid[x][y] == '1' and not is_visited[x][y] 
      # Set the currently found cell to true & increment the island_count
      is_visited[x][y] = true
      island_count += 1
      
      # BFS through its neighbor and set is_visited for all the adjacent 1s to true
      check_queue = [[x,y]]
      loop do
        checked = check_queue.pop()
        puts "#{checked[0]},#{checked[1]}"
        if checked[0]+1 < grid.length() and checked[1] < grid[x].length() and grid[checked[0]+1][checked[1]] == '1' and not is_visited[checked[0]+1][checked[1]]
            is_visited[checked[0]+1][checked[1]] = true
            check_queue.push([checked[0]+1, checked[1]])
        end
        
        if checked[0] < grid.length() and checked[1]-1 >= 0 and grid[checked[0]][checked[1]-1] == '1' and not is_visited[checked[0]][checked[1]-1]
            is_visited[checked[0]][checked[1]-1] = true
            check_queue.push([checked[0], checked[1]-1])
        end
        
        if checked[0] - 1 >= 0 and checked[1] >= 0 and grid[checked[0] - 1][checked[1]] == '1' and not is_visited[checked[0] - 1][checked[1]]
            is_visited[checked[0] - 1][checked[1]] = true
            check_queue.push([checked[0] - 1, checked[1]])
        end
        
        if checked[0] >= 0 and checked[1]+1 < grid[x].length() and grid[checked[0]][checked[1]+1] == '1' and not is_visited[checked[0]][checked[1]+1]
            is_visited[checked[0]][checked[1]+1] = true
            check_queue.push([checked[0], checked[1] +1])
        end
        
        break unless check_queue.any?
      end
      
    end
    
  end
end

puts "Island count: #{island_count}"
