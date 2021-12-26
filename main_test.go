package main

import (
	"reflect"
	"testing"
)

func TestInitialize(t *testing.T) {
	want := cards{
		1: Card{"クラブ", "A", 1, false},
		2: Card{"クラブ", "2", 2, false},
		3: Card{"クラブ", "3", 3, false},
		4: Card{"クラブ", "4", 4, false},
		5: Card{"クラブ", "5", 5, false},
		6: Card{"クラブ", "6", 6, false},
		7: Card{"クラブ", "7", 7, false},
		8: Card{"クラブ", "8", 8, false},
		9: Card{"クラブ", "9", 9, false},
		10: Card{"クラブ", "10", 10, false},
		11: Card{"クラブ", "J", 10, false},
		12: Card{"クラブ", "Q", 10, false},
		13: Card{"クラブ", "K", 10, false},
		14: Card{"ダイヤ", "A", 1, false},
		15: Card{"ダイヤ", "2", 2, false},
		16: Card{"ダイヤ", "3", 3, false},
		17: Card{"ダイヤ", "4", 4, false},
		18: Card{"ダイヤ", "5", 5, false},
		19: Card{"ダイヤ", "6", 6, false},
		20: Card{"ダイヤ", "7", 7, false},
		21: Card{"ダイヤ", "8", 8, false},
		22: Card{"ダイヤ", "9", 9, false},
		23: Card{"ダイヤ", "10", 10, false},
		24: Card{"ダイヤ", "J", 10, false},
		25: Card{"ダイヤ", "Q", 10, false},
		26: Card{"ダイヤ", "K", 10, false},
		27: Card{"ハート", "A", 1, false},
		28: Card{"ハート", "2", 2, false},
		29: Card{"ハート", "3", 3, false},
		30: Card{"ハート", "4", 4, false},
		31: Card{"ハート", "5", 5, false},
		32: Card{"ハート", "6", 6, false},
		33: Card{"ハート", "7", 7, false},
		34: Card{"ハート", "8", 8, false},
		35: Card{"ハート", "9", 9, false},
		36: Card{"ハート", "10", 10, false},
		37: Card{"ハート", "J", 10, false},
		38: Card{"ハート", "Q", 10, false},
		39: Card{"ハート", "K", 10, false},
		40: Card{"スペード", "A", 1, false},
		41: Card{"スペード", "2", 2, false},
	    42: Card{"スペード", "3", 3, false},
		43: Card{"スペード", "4", 4, false},
		44: Card{"スペード", "5", 5, false},
		45: Card{"スペード", "6", 6, false},
		46: Card{"スペード", "7", 7, false},
		47: Card{"スペード", "8", 8, false},
		48: Card{"スペード", "9", 9, false},
		49: Card{"スペード", "10", 10, false},
		50: Card{"スペード", "J", 10, false},
		51: Card{"スペード", "Q", 10, false},
		52: Card{"スペード", "K", 10, false},
	}
	if !reflect.DeepEqual(initialize(), want) {
		t.Errorf("initialize() = %v,\nwant %v", initialize(), want)
	}
}