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

interface Position {
    x: number;
    y: number;
}

class Game {
    public gameBoardWidth: number;
    public gameBoardHeight: number;
    public mPosition: Position;
    public hPosition: Position;

    public container: string[] = [];

    constructor(
        gameBoardWidth: number,
        gameBoardHeight: number,
        mPosition: Position,
        hPosition: Position
    ) {
        this.gameBoardWidth = gameBoardWidth;
        this.gameBoardHeight = gameBoardHeight;
        this.mPosition = mPosition;
        this.hPosition = hPosition;
        this.render();
    }

    public render() {
        for (let i = 0; i < this.gameBoardHeight; i++) {
            let wall: string = "X";

            for (let j = 1; j < this.gameBoardWidth; j++) {
                if (i === 0 || i === this.gameBoardHeight - 1) {
                    wall += "X";
                } else {
                    if (j === this.gameBoardWidth - 1) {
                        wall += "X";
                    } else {
                        if (i === this.mPosition.x && j === this.mPosition.y) {
                            wall += "M";
                        } else if (
                            i === this.hPosition.x &&
                            j === this.hPosition.y
                        ) {
                            wall += "H";
                        } else {
                            wall += ".";
                        }
                    }
                }
            }

            this.container.push(wall);
        }
    }
}

const m: Position = { x: 3, y: 2 };
const h: Position = { x: 1, y: 8 };

const game = new Game(13, 6, m, h);

console.log(game);
