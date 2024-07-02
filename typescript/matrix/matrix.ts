export class Matrix {
  private _mat: number[][] = new Array();

  // inputs: 
  // 1. mat_str = string that defines a matrix
  //    - spaces separate row entries
  //    - newlines (`\n`) separate rows
  //    - ex: '1 3 5\n2 4 6\n3 5 7'

  constructor(public mat_str: string) {
    let row_arr: string[] = mat_str.split('\n'); // space separated list of numbers
    const num_rows = row_arr.length; // len ['1 3 5', '2 4 6', '3 5 7'] = 3
    for(let r: number = 0; r < num_rows; r++){
      this._mat.push(row_arr[r].split(' ').map(Number));
    };
  }

  get rows(): number[][] {
    let rows: number[][] = new Array();
    for( let r = 0; r < this._mat.length; r++) {
      rows.push(this._mat[r]);
    }
    return rows;
  }

  get columns(): number[][] {
    let cols: number[][] = new Array();
    const arrayColumn = (arr: number[][], n: number) => arr.map(x => x[n]);
    for( let c = 0; c < this._mat[0].length; c++) {
      cols.push(arrayColumn(this._mat, c));
    }
    return cols;
  }
}
