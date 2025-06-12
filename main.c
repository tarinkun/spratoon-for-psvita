#include <vitasdk.h> // VitaSDKヘッダーファイル
#include <psp2d.h>   // 2Dグラフィックスライブラリ 
#include <vita2d.h>  // 3Dグラフィックスライブラリ 
#include <math.h>
#include <string>
#include <vector>
#include "player.h" // プレイヤーキャラクターのクラス
// #include "world.h"  // ゲーム世界のクラス
// #include "projectile.h" // 弾丸のクラス

enum WeaponType {
    WEAPON_SHORT_RANGE,
    WEAPON_MIDDLE_RANGE,
    WEAPON_LONG_RANGE,
    NUM_WEAPON_TYPES
};

struct WeaponStats {
    WeaponType type;
    float range;
    float damage;
    float fireRate;
};

WeaponStats g_weaponStats[NUM_WEAPON_TYPES] = {
    {WEAPON_SHORT_RANGE, 5.0f, 10.0f, 0.07f}, // 短射程シューター
    {WEAPON_MIDDLE_RANGE, 10.0f, 8.0f, 0.2f}, // 中射程ブラスター
    {WEAPON_LONG_RANGE, 20.0f, 5.0f, 0.6f},   // 長射程チャージャー
};


// ゲームの状態を管理する構造体
struct GameState {
    // プレイヤーの位置、方向、状態
    // 弾丸のリスト
    // 地形データ
    // UI関連の変数


    // 現在のゲーム画面の状態を管理 (タイトル、武器選択、ゲームプレイなど)
    enum GameScreenState {
        SCREEN_TITLE,
        SCREEN_WEAPON_SELECTION,
        SCREEN_GAMEPLAY,
        SCREEN_GAMEOVER
    } currentScreen;
WeaponType currentWeaponSelection; // UI上で現在選択されている武器の種類 (インデックス) 
playerWeapon;//プレイヤー装備武器のデータ

    WeaponType currentWeaponSelection; // UI上で現在選択されている武器の種類
    WeaponStats*
playerWeapon;         // プレイヤーが現在装備している武器のデータへのポインタ

    // その他、ゲームに必要なデータ
};
// ゲームの状態を管理するグローバル変数や構造体
struct GameState {
    // プレイヤーの位置、方向、状態
    // 弾丸のリスト
    // 地形データ
    //UI
    // ゲームフェーズ (タイトル、ゲーム中、ゲームオーバー等)
    // その他
};

// ゲーム初期化
void initGame(GameState& state) {
    // VitaSDKの初期化
    sceKernelExitDeleteThread(0); // スレッドの終了処理（VitaSDKの一般的な初期化ルーチンの一部）

    // グラフィックスライブラリの初期化 (例: vita2d)
    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF)); // 背景色を黒に設定

    // コントローラーの初期化
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);

    // ゲーム状態の初期値設定
    // state.player_pos = {0, 0, 0};みたいなのを想定
    // ...
}

// イベント処理関数 (入力、ネットワークメッセージなど)
void handleInput(GameState& state) {
    SceCtrlData pad;
    sceCtrlReadBufferPositive(0, &pad, 1);

    // Lスティックでプレイヤーを移動予定
    if (pad.lx < 64) { /* 左へ移動 */ }
    if (pad.lx > 192) { /* 右へ移動 */ }
    if (pad.ly < 64) { /* 上へ移動 */ }
    if (pad.ly > 192) { /* 下へ移動 */ }

    // Rボタンで発射(予定)
    if (pad.buttons & SCE_CTRL_R1) {
        // 弾丸を生成し、リストに追加(後で考える)
    }
    // その他のボタン入力やタッチスクリーン入力などここで
}

// ゲームロジック更新関数
void updateGame(GameState& state, float deltaTime) {
    // プレイヤーの動
    // インクの移動、衝突判定
    // インクの描画ロジック (テクスチャのマッピング、インクの広がり方など)
    // 敵AIの更新
    // スコア計算
    // タイマーの更新
    // ネットワーク同期 (要らないと思う)
    // 物理演算 (重力、摩擦など)
    // その他のゲームルール
}

// 描画関数
void renderGame(const GameState& state) {
    vita2d_start_drawing();

    // 背景の描画
    vita2d_clear_screen();

    // 地形の描画 (3Dモデル、テクスチャ)
    // vita2d_draw_rect(x, y, width, height, color); // 例: 2Dでの簡易な地形
    // vita2d_draw_texture(texture, x, y); // 例: テクスチャで地形を描画

    // インクの描画 (インクが塗られた部分を表現)
    // スプラトゥーンでは、テクスチャやレンダーターゲットを操作してインクを表現することが多いです。

    // プレイヤーの描画 (3Dモデルまたはスプライト)
    // vita2d_draw_texture_rot(texture, x, y, angle);

    // 弾丸の描画
    // UIの描画 (スコア、残弾数、マップなど)
    // vita2d_pgf_draw_text(font, x, y, RGBA8(0xFF, 0xFF, 0xFF, 0xFF), 1.0f, "Score: %d", state.score);

    vita2d_end_drawing();
    vita2d_swap_buffers(); // 描画バッファを交換して画面に表示
}

// ゲーム終了処理関数
void shutdownGame(GameState& state) {
    // グラフィックスライブラリの終了処理
    vita2d_fini();
}

int main() {
    GameState gameState; // ゲームの状態を保持する変数

    initGame(gameState); // ゲームの初期化

    // メインゲームループ
    while (true) {
        handleInput(gameState);       // 入力を処理
        updateGame(gameState, 1.0f / 60.0f); // ゲームロジックを更新 (例: 60FPS)
        renderGame(gameState);        // 画面を描画

      
        sceKernelDelayThread(1000000 / 75);
    }

    shutdownGame(gameState); // ゲーム終了処理

    return 0;
}
