# Smart Tic-Tac-Toe AI

A console-based Tic-Tac-Toe game written in C++ featuring an unbeatable AI powered by the Minimax Algorithm with Alpha-Beta Pruning.

## Overview

This project implements a smart Tic-Tac-Toe opponent that evaluates every possible future game state before making a move.

Unlike traditional rule-based opponents, the AI uses game theory and search algorithms to always select the optimal move.

The result is an AI that:

- Never loses
- Always blocks winning moves
- Always takes winning opportunities
- Forces a draw when a win is impossible

---

## Features

- Human vs Computer gameplay
- Minimax Algorithm
- Alpha-Beta Pruning optimization
- Input validation
- Randomized selection among equally optimal moves
- Efficient game state evaluation
- Clean terminal interface

---

## Algorithms Used

### Minimax Algorithm

The AI recursively explores all possible future board states and assigns scores based on outcomes:

- Win = Positive score
- Loss = Negative score
- Draw = Neutral score

The move with the highest score is selected.

### Alpha-Beta Pruning

To improve performance, unnecessary branches of the search tree are skipped.

Benefits:

- Faster decision making
- Reduced computation
- Same optimal result as standard Minimax

---

## Why the AI Never Loses

The AI evaluates every possible future game state before making a move.

Using the Minimax algorithm, it assumes that:

- The computer always plays optimally.
- The human player also plays optimally.

As a result, the AI:

- Takes a winning move whenever one exists.
- Blocks the player's winning moves.
- Avoids moves that lead to a loss.
- Forces a draw when a win is impossible.

This guarantees that the AI can never be defeated.

## Technical Highlights

- Recursive game tree search
- Alpha-Beta pruning optimization
- Depth-based scoring system
- Input validation and error handling
- Randomized selection among equally optimal moves

## Project Structure

```text
tic-tac-toe-minimax-ai
│
├── main.cpp
├── README.md
├── LICENSE
├── .gitignore
└── assets/
```

## Code Architecture

| Function | Responsibility |
|-----------|---------------|
| drawBoard() | Renders the current board state |
| playerMove() | Processes and validates user input |
| computerMove() | Initiates AI move selection |
| checkWinner() | Detects game-winning states |
| checkTie() | Detects draw conditions |
| get_winner() | Evaluates board outcome for Minimax |
| minimax() | Performs recursive game-tree search with Alpha-Beta Pruning |
| best_move() | Selects the highest-scoring move |

## AI Decision Flow

1. Generate all possible legal moves.
2. Simulate each move.
3. Evaluate future game states using Minimax.
4. Apply Alpha-Beta Pruning to eliminate unnecessary branches.
5. Assign scores to outcomes.
6. Select the move with the highest score.
7. Randomly choose among equally optimal moves.

## Example Gameplay

```text
     |     |
     |     |
_____|_____|_____
     |     |
     |     |
_____|_____|_____
     |     |
     |     |
     |     |

Enter a spot to place a marker (1-9): 5

     |     |
     |     |
_____|_____|_____
     |     |
     |  X  |
_____|_____|_____
     |     |
     |     |
     |     |

Computer placed at 9

     |     |
     |     |
_____|_____|_____
     |     |
     |  X  |
_____|_____|_____
     |     |
     |     |  O
     |     |

Enter a spot to place a marker (1-9): 7

     |     |
     |     |
_____|_____|_____
     |     |
     |  X  |
_____|_____|_____
     |     |
  X  |     |  O
     |     |

Computer placed at 3

     |     |
     |     |  O
_____|_____|_____
     |     |
     |  X  |
_____|_____|_____
     |     |
  X  |     |  O
     |     |

Enter a spot to place a marker (1-9): 6

     |     |
     |     |  O
_____|_____|_____
     |     |
     |  X  |  X
_____|_____|_____
     |     |
  X  |     |  O
     |     |

Computer placed at 4

     |     |
     |     |  O
_____|_____|_____
     |     |
  O  |  X  |  X
_____|_____|_____
     |     |
  X  |     |  O
     |     |

Enter a spot to place a marker (1-9): 2

     |     |
     |  X  |  O
_____|_____|_____
     |     |
  O  |  X  |  X
_____|_____|_____
     |     |
  X  |     |  O
     |     |

Computer placed at 8

     |     |
     |  X  |  O
_____|_____|_____
     |     |
  O  |  X  |  X
_____|_____|_____
     |     |
  X  |  O  |  O
     |     |

Enter a spot to place a marker (1-9): 1

     |     |
  X  |  X  |  O
_____|_____|_____
     |     |
  O  |  X  |  X
_____|_____|_____
     |     |
  X  |  O  |  O
     |     |

IT'S A TIE!
Thanks for playing!
```

---

## AI Evaluation Strategy

The Minimax algorithm assigns scores to terminal game states:

| Outcome | Score |
|----------|--------|
| AI Win | +10 - depth |
| Player Win | depth - 10 |
| Draw | 0 |

The depth adjustment encourages:

- Faster wins
- Delayed losses
- Optimal decision making

This allows the AI to distinguish between multiple winning or losing paths and select the most favorable outcome.

## Complexity

The Minimax algorithm explores a game tree of possible board states.

- Time Complexity (Minimax): O(b^d)
- Space Complexity: O(d)

Where:

- b = branching factor
- d = search depth

Alpha-Beta Pruning reduces the number of explored states while preserving optimal play, significantly improving practical performance.

## Learning Outcomes

Through this project I learned:

- Recursive algorithms
- Game tree search
- Minimax strategy
- Alpha-Beta pruning
- State-space exploration
- C++ memory handling
- Input validation techniques

---

## Future Improvements

- GUI version using SFML
- Difficulty levels
- Statistics tracking
- Multiplayer mode
- Reinforcement Learning based opponent
- Web-based version

---

## Author

Alan P Ali

Computer Science and Engineering

Government Engineering College Thrissur
