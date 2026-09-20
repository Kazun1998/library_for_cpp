# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 概要

C++ 競技プログラミング用のヘッダオンリーライブラリ。アルゴリズム・データ構造ごとに、リポジトリ直下のトピックディレクトリ(例: `Segment_Tree/`, `Graph/`, `Union_Find/`)に `.hpp` ファイルとして置かれている。各ヘッダは `#pragma once` を使い、検証用コード等から相対パスで直接 `#include` される想定(例: `#include "../../../Tree/Lowest_Common_Ancestor.hpp"`)。

ほぼ全てのヘッダが `template/template.hpp` に依存している。ここには共通の include 群、`using namespace std;`、ライブラリ全体で使う typedef やマクロがまとまっている。

## 検証(verify)の仕組み

正しさの担保は `online-judge-verify-helper`(`oj-verify`)を使い、各ライブラリのヘッダをジャッジの問題に対して実際に実行することで行っている(設定は `.verify-helper/config.toml`、コンパイラは `g++-13 -std=c++23 -O3 -Wall -g`)。

- `verify/<judge>/<category>/*.cpp` — 検証用ファイル。先頭に検証対象の問題URLを示す `#define PROBLEM "<url>"` を書き、続けて検証したいライブラリヘッダを include し、その問題の入出力を行う `main()` を書く。
- 使用しているジャッジ: `aizu_online_judge`, `yosupo_library_checker`, `yukicoder`。加えて手書きのストレステスト用に `verify/original` がある。
- 全件検証: `oj-verify all`
- 単一ファイルの検証: `oj-verify run verify/<judge>/<category>/<file>.cpp`
- CI(`.github/workflows/*.yml`)は push のたびに `oj-verify all` を実行する。認証が必要なジャッジ向けに `YUKICODER_TOKEN` / `GH_PAT` を secrets として使用。
- `oj-verify` を使うには `online-judge-verify-helper` パッケージのインストールが必要(`pip install -U git+https://github.com/Kazun1998/verification-helper.git`)。

ライブラリのヘッダを追加・変更したときは、対応する検証ファイルを `verify/` 配下に追加・更新し、実際のジャッジ問題で動作を確認すること。このリポジトリでは通常の単体テストの代わりに、これがライブラリの正しさを証明する手段になっている。

## ドキュメント生成

`oj-verify` は各 `.hpp` に埋め込まれた特殊な Markdown コメントブロックと、ライブラリと同じ構成でミラーされた `Document/<Topic>/` 配下のファイルから、ドキュメントサイト(GitHub Pages)を生成する。生成・キャッシュされた出力は `.verify-helper/markdown/` に置かれる(手動編集はしない)。

## `jam` / `jam.cpp`

`jam` はローカルでの動作確認・実験用にビルド済みのバイナリ(ソースは `jam.cpp`)。複数のライブラリヘッダを一緒に include した `main()` の例になっている。検証対象のライブラリ本体ではない。

## ヘッダ追加時の規約

- 新規ファイルはヘッダオンリーとし、先頭は `#pragma once`、続けて `#include "../template/template.hpp"` を書く(ディレクトリの深さに応じてパスの `../` の数は調整する)。
- 汎用的なアルゴリズムは、値・モノイドの型と比較関数/演算をテンプレート引数として受け取る形にする(パターンは `Segment_Tree/Segment_Tree.hpp` の `template<typename M, typename Op>` を参照)。
- 新規ヘッダは既存のトピックディレクトリのうち適切なものに配置する(どれにも当てはまらない場合のみ新規ディレクトリを作る)。あわせて `verify/` 配下に対応する検証ファイルを追加する。
