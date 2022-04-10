/**

input:
- gameBoardWidth: int
- gameBoardHeight: int
- mPosition: ?
- hPosition: ?

output:

function render(input: ...): string[]

[
  "XXXXXXXXXXXXX",
  "X.......H...X",
  "X...........X",
  "X.M.........X",
  "X...........X",
  "XXXXXXXXXXXXX",
]

*/
class Game {
    constructor(gameBoardWidth, gameBoardHeight, mPosition, hPosition) {
        this.container = [];
        this.gameBoardWidth = gameBoardWidth;
        this.gameBoardHeight = gameBoardHeight;
        this.mPosition = mPosition;
        this.hPosition = hPosition;
        this.render();
    }
    render() {
        for (let i = 0; i < this.gameBoardHeight; i++) {
            let wall = "X";
            for (let j = 1; j < this.gameBoardWidth; j++) {
                if (i === 0 || i === this.gameBoardHeight - 1) {
                    wall += "X";
                }
                else {
                    if (j === this.gameBoardWidth - 1) {
                        wall += "X";
                    }
                    else {
                        if (i === this.mPosition.x && j === this.mPosition.y) {
                            wall += "M";
                        }
                        else if (i === this.hPosition.x &&
                            j === this.hPosition.y) {
                            wall += "H";
                        }
                        else {
                            wall += ".";
                        }
                    }
                }
            }
            this.container.push(wall);
        }
    }
}
const m = { x: 3, y: 2 };
const h = { x: 1, y: 8 };
const game = new Game(13, 6, m, h);
console.log(game);
